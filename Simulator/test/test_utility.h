#ifndef GAMEOFLIFE_TEST_UTILITY_H
#define GAMEOFLIFE_TEST_UTILITY_H

#include "Simulator/src/rules_creator.h"
#include "ThirdParty/fmt/include/fmt/core.h"
#include "ThirdParty/fmt/include/fmt/ranges.h"

namespace TestUtility
{

std::string PrintCurrentCellState(const CellNeighborhoodStates& state)
{
    return fmt::format("Current cell state {}", fmt::join(state, "-"));
}

}  // namespace TestUtility

#endif  // GAMEOFLIFE_TEST_UTILITY_H
