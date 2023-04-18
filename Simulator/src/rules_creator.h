#ifndef GAMEOFLIFE_GUI_SRC_RULES_H_
#define GAMEOFLIFE_GUI_SRC_RULES_H_

#include <map>

#include "Simulator/src/data.h"

namespace RulesCreator
{
/// @brief Creates a list of all possible rules.
/// @return List of all rules
Rules CreateListOfRules();

/// @brief Maps all possible cell neighborhood states with the selected rule.
/// @param rule Rule which shall be used
/// @return Mapped all possible cell neighborhood states with the selected rule
std::map<CellNeighborhoodStates, bool> MapCellNeighborhoodStatesWithRuleOutput(const std::bitset<8>& rule);
}  // namespace RulesCreator

#endif  // GAMEOFLIFE_GUI_SRC_RULES_H_
