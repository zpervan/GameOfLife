#ifndef GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
#define GAMEOFLIFE_SIMULATOR_SRC_DATA_H_

#include <vector>
#include <string>
#include <bitset>

using Rule = std::pair<std::string, std::bitset<8>>;
/// @todo: More creative name! (Clashes with "Rules" namespace that why it's called "Rules")
using Rules = std::vector<Rule>;

namespace Data {
    static Rule current_rule;
    static Rules rules;
    static std::bitset<8> initial_cell_state;
}

#endif //GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
