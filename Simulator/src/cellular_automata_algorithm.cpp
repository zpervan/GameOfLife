#include "Simulator/src/cellular_automata_algorithm.h"

#include "Simulator/src/rules_creator.h"

void CellularAutomataAlgorithm::SetRule(const std::bitset<8> &rule) {
    cell_neighborhood_states_to_rule_output_ = RulesCreator::MapCellNeighborhoodStatesWithRuleOutput(rule);
}

void CellularAutomataAlgorithm::SetInitialCellGenerationState(const std::vector<bool> &initial_cell_generation) {
    previous_cell_generation_ = initial_cell_generation;
    new_cell_generation_.reserve(previous_cell_generation_.size());
}

std::optional<bool> CellularAutomataAlgorithm::CreateNewCellState(std::size_t middle_cell_index) {
    if (previous_cell_generation_.size() == middle_cell_index) {
        return std::nullopt;
    }

    const bool left_neighbor_cell{GetLeftNeighborCell(middle_cell_index)};
    const bool middle_cell{previous_cell_generation_[middle_cell_index]};
    const bool right_neighbor_cell{GetRightNeighborCell(middle_cell_index)};

    const std::array<bool, 3> current_cell_neighborhood_state{left_neighbor_cell, middle_cell, right_neighbor_cell};

    const bool new_cell_state{cell_neighborhood_states_to_rule_output_.find(current_cell_neighborhood_state)->second};
    new_cell_generation_.emplace_back(new_cell_state);

    ResetCellStatesIfNewCellGenerationIsComplete(middle_cell_index);

    return new_cell_state;
}

bool CellularAutomataAlgorithm::GetLeftNeighborCell(std::size_t cell_index) {
    return cell_index == 0 ? previous_cell_generation_.back() : previous_cell_generation_.at(cell_index - 1);
}

bool CellularAutomataAlgorithm::GetRightNeighborCell(std::size_t cell_index) {
    return cell_index == previous_cell_generation_.size() - 1 ? previous_cell_generation_.front()
                                                              : previous_cell_generation_.at(cell_index + 1);
}

void CellularAutomataAlgorithm::ResetCellStatesIfNewCellGenerationIsComplete(size_t column_index) {
    if (previous_cell_generation_.size() - 1 == column_index) {
        previous_cell_generation_ = new_cell_generation_;
        new_cell_generation_.clear();
    }
}
