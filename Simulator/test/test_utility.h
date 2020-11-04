#ifndef GAMEOFLIFE_TEST_UTILITY_H
#define GAMEOFLIFE_TEST_UTILITY_H

#include "ThirdParty/fmt/include/fmt/core.h"
#include "ThirdParty/fmt/include/fmt/ranges.h"

namespace TestUtility {
    std::string PrintCurrentCellState(const CellNeighborState &state) {
        return fmt::format("Current cell state {}", fmt::join(state, "-"));
    }
}

#endif //GAMEOFLIFE_TEST_UTILITY_H
