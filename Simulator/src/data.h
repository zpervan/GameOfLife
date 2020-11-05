#ifndef GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
#define GAMEOFLIFE_SIMULATOR_SRC_DATA_H_

#include <vector>
#include <string>
#include <bitset>
#include <array>

using Rule = std::pair<std::string, std::bitset<8>>;
/// @todo: More creative name! (Clashes with "Rules" namespace that why it's called "Rules")
using Rules = std::vector<Rule>;
using CellNeighborhoodStates = std::array<bool, 3>;

namespace Data {
    static Rule selected_rule;
    static Rules rules;
    static std::bitset<8> initial_cell_state;
}

namespace Cell {
    static std::size_t row_{0};
    static std::size_t column_{0};
}

struct SimulatorState {
    bool run{false};
    bool pause{false};
    bool stop{false};
};

#endif //GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
