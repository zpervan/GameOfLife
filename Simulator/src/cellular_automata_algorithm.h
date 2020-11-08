#ifndef GAMEOFLIFE_CELLULAR_AUTOMATA_ALGORITHM_H
#define GAMEOFLIFE_CELLULAR_AUTOMATA_ALGORITHM_H

#include "Simulator/src/data.h"
#include <bitset>
#include <optional>
#include <map>
#include <vector>

using CellStates = std::vector<bool>;

/// @brief Contains all the cellular automata generation logic.
class CellularAutomataAlgorithm {
public:
    /// @brief Sets the rule which will applied in the creation of new cell generations.
    /// @param rule Rule which shall be applied
    void SetRule(const std::bitset<8> &rule);

    /// @brief Sets the initial cell generation states from which the algorithm will start it's generation of new cells.
    /// @param initial_cell_generation Contains the initial cell generation states represented with bools
    void SetInitialCellGenerationState(const std::vector<bool> &initial_cell_generation);

    /// @brief Creates a new cell state and it is dependant of the previous cell generation neighborhood.
    /// @param middle_cell_index Represents the currently processed neighborhood of the previous cell generation
    /// @return New cell state in the new cell generation
    std::optional<bool> CreateNewCellState(std::size_t middle_cell_index);

private:
    bool GetLeftNeighborCell(std::size_t cell_index);

    bool GetRightNeighborCell(std::size_t cell_index);

    void ResetCellStatesIfNewCellGenerationIsComplete(size_t column_index);

    std::map<CellNeighborhoodStates, bool> cell_neighborhood_states_to_rule_output_;
    CellStates new_cell_generation_;
    CellStates previous_cell_generation_;
};

#endif //GAMEOFLIFE_CELLULAR_AUTOMATA_ALGORITHM_H
