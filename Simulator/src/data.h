#ifndef GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
#define GAMEOFLIFE_SIMULATOR_SRC_DATA_H_

#include <vector>
#include <string>
#include <bitset>

namespace Data
{
	static std::vector<std::pair<std::string, std::bitset<8>>> rules;
	static std::pair<std::string, std::bitset<8>> current_rule;
	static std::bitset<8> initial_cell_state;
}

#endif //GAMEOFLIFE_SIMULATOR_SRC_DATA_H_
