#include "Simulator/src/rules_creator.h"
#include "ThirdParty/fmt/include/fmt/core.h"
#include <bitset>

namespace RuleCreator {
    Rules CreateBasicRules() {
        constexpr std::size_t rules_count{256};

        Rules rules;
        rules.reserve(rules_count);

        for (std::size_t i{0}; i < rules_count; i++) {
            rules.emplace_back(fmt::format("Rule {}", i), std::bitset<8>(i));
        }

        return rules;
    }
}


