#ifndef GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
#define GAMEOFLIFE_SIMULATOR_SRC_DATA_H_

#include <array>
#include <bitset>
#include <vector>
#include <string>

using Rule = std::pair<std::string, std::bitset<8>>;
using Rules = std::vector<Rule>;
using CellNeighborhoodStates = std::array<bool, 3>;

namespace Cell {
    static std::size_t row_;
    static std::size_t column_;
}

enum class SimulatorState {
    INITIALIZATION = 0,
    RUN,
    PAUSE,
    STOP,
    NO_CHANGE
};

#endif //GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
