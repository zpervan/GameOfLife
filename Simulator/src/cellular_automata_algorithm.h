#ifndef GAMEOFLIFE_CELLULAR_AUTOMATA_ALGORITHM_H
#define GAMEOFLIFE_CELLULAR_AUTOMATA_ALGORITHM_H

#include "Simulator/src/data.h"

#include "Simulator/src/rules_creator.h"
#include <vector>

using CellStates = std::vector<bool>;

class CellularAutomataAlgorithm {
public:
    std::optional<bool> CreateNewCellState(std::size_t column_index);

    void SetRule(const std::bitset<8> &rule);

    void SetInitialCellState(const std::vector<bool> &initial_cell_states);

private:
    bool GetLeftNeighborCell(std::size_t index);

    void ResetCellStatesIfNewCellGenerationIsComplete(size_t column_index);

    bool GetRightNeighborCell(std::size_t index);

    std::map<CellNeighborhoodStates, bool> cell_neighborhood_states_to_rule_output_;
    CellStates new_cell_generation_;
    CellStates previous_cell_generation_;
};


#endif //GAMEOFLIFE_CELLULAR_AUTOMATA_ALGORITHM_H
