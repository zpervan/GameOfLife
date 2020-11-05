#include "Simulator/src/cellular_automata_algorithm.h"

void CellularAutomataAlgorithm::SetRule(const std::bitset<8> &rule) {
    cell_neighborhood_states_to_rule_output_ = RulesCreator::MapCellNeighborhoodStatesWithRuleOutput(rule);
}

void CellularAutomataAlgorithm::SetInitialCellState(const std::vector<bool> &initial_cell_states) {
    previous_cell_generation_ = initial_cell_states;
    new_cell_generation_.reserve(previous_cell_generation_.size());
}

std::optional<bool> CellularAutomataAlgorithm::CreateNewCellState(std::size_t column_index) {
    if (previous_cell_generation_.size() == column_index) {
        return std::nullopt;
    }

    const bool left_neighbor_cell{GetLeftNeighborCell(column_index)};
    const bool middle_cell{previous_cell_generation_[column_index]};
    const bool right_neighbor_cell{GetRightNeighborCell(column_index)};

    const std::array<bool, 3> current_cell_neighborhood_state{left_neighbor_cell, middle_cell, right_neighbor_cell};

    const bool new_cell_state{cell_neighborhood_states_to_rule_output_.find(current_cell_neighborhood_state)->second};
    new_cell_generation_.emplace_back(new_cell_state);

    ResetCellStatesIfNewCellGenerationIsComplete(column_index);

    return new_cell_state;
}

bool CellularAutomataAlgorithm::GetLeftNeighborCell(std::size_t index) {
    return index == 0 ? previous_cell_generation_.back() : previous_cell_generation_.at(index - 1);
}

bool CellularAutomataAlgorithm::GetRightNeighborCell(std::size_t index) {
    return index == previous_cell_generation_.size() - 1 ? previous_cell_generation_.front()
                                                         : previous_cell_generation_.at(index + 1);
}

void CellularAutomataAlgorithm::ResetCellStatesIfNewCellGenerationIsComplete(size_t column_index) {
    if (previous_cell_generation_.size() - 1 == column_index) {
        previous_cell_generation_ = new_cell_generation_;
        new_cell_generation_.clear();
    }
}
