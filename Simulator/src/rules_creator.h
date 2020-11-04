#ifndef GAMEOFLIFE_GUI_SRC_RULES_H_
#define GAMEOFLIFE_GUI_SRC_RULES_H_

#include "Simulator/src/data.h"
#include <map>

namespace RuleCreator {
    Rules CreateBasicRules();

    std::map<CellNeighborhoodStates, bool> MapCellNeighborhoodStatesWithRules(std::bitset<8> rule);
}

#endif //GAMEOFLIFE_GUI_SRC_RULES_H_
