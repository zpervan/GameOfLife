#ifndef GAMEOFLIFE_GUI_SRC_RULES_H_
#define GAMEOFLIFE_GUI_SRC_RULES_H_

#include "ThirdParty/fmt/include/fmt/core.h"

#include <array>
#include <string>
#include <bitset>

namespace Rules
{
	std::vector<std::pair<std::string, std::bitset<8>>> CreateBasicRules()
	{
	  std::vector<std::pair<std::string, std::bitset<8>>> rules;
	  constexpr std::size_t rules_count{256};
	  rules.reserve(rules_count);

	  for (std::size_t i{0}; i <= 255; i++)
	  {
		rules.emplace_back(fmt::format("Rule {}", i), std::bitset<8>(i));
	  }
	  return rules;
	}
}

#endif //GAMEOFLIFE_GUI_SRC_RULES_H_
