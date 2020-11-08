#include "Simulator/src/rules_creator.h"

#include "ThirdParty/fmt/include/fmt/core.h"
#include <bitset>

Rules RulesCreator::CreateListOfRules() {
    constexpr std::size_t rules_count{256};

    Rules rules;
    rules.reserve(rules_count);

    for (std::size_t i{0}; i < rules_count; i++) {
        rules.emplace_back(fmt::format("Rule {}", i), std::bitset<8>(i));
    }

    return rules;
}

std::map<CellNeighborhoodStates, bool>
RulesCreator::MapCellNeighborhoodStatesWithRuleOutput(const std::bitset<8> &rule) {
    std::map<CellNeighborhoodStates, bool> cell_states_;

    for (std::size_t i{0}; i < rule.size(); i++) {
        std::bitset<3> current_states{i};
        CellNeighborhoodStates states{current_states[2], current_states[1], current_states[0]};
        cell_states_[states] = rule[i];
    }
    return cell_states_;
}
