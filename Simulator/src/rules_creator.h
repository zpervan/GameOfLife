#ifndef GAMEOFLIFE_GUI_SRC_RULES_H_
#define GAMEOFLIFE_GUI_SRC_RULES_H_

#include "Simulator/src/data.h"
#include <map>

namespace RulesCreator {
    Rules CreateListOfRules();

    std::map<CellNeighborhoodStates, bool> MapCellNeighborhoodStatesWithRuleOutput(const std::bitset<8> &rule);
}

#endif //GAMEOFLIFE_GUI_SRC_RULES_H_
