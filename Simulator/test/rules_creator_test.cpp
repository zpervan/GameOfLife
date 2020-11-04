#include "Simulator/src/rules_creator.h"

#include "ThirdParty/fmt/include/fmt/core.h"
#include "gtest/gtest.h"

TEST(RulesTest, GivenCallToBasicRulesCreation_WhenCreated_ThenRulesCorrectlyCreated) {
    constexpr std::size_t expected_size{256};

    const auto &rules{RuleCreator::CreateBasicRules()};

    ASSERT_EQ(rules.size(), expected_size);

    for (std::size_t i{0}; i <= 255; i++) {
        const std::bitset<8> expected_binary_rule_representation{i};
        const std::string expected_rule_name{fmt::format("Rule {}", i)};

        const auto&[actual_rule_name, actual_binary_rule_representation] = rules.at(i);

        EXPECT_EQ(actual_rule_name, expected_rule_name);
        EXPECT_EQ(actual_binary_rule_representation, expected_binary_rule_representation);
    }
}

class RulesCreatorTestFixture : public testing::TestWithParam<std::pair<CellNeighborhoodStates, bool>> {
};

TEST_P(RulesCreatorTestFixture, GivenValidRule_WhenMappingCellNeighborStatesWithNewCellState_ThenMappingIsCorrect) {
    const auto &[cell_neighborhood_states, expected_rule_cell_state] = GetParam();

    const std::bitset<8> rule{30};
    const auto &mapped_cell_states_with_rules{RuleCreator::MapCellNeighborhoodStatesWithRules(rule)};

    const auto &actual_rule_cell_state{mapped_cell_states_with_rules.find(cell_neighborhood_states)};
    EXPECT_EQ(actual_rule_cell_state->second, expected_rule_cell_state);
}

INSTANTIATE_TEST_SUITE_P(RuleMappingParametrizedTest, RulesCreatorTestFixture,
                         testing::Values(std::make_pair<CellNeighborhoodStates, bool>({0, 0, 0}, 0),
                                         std::make_pair<CellNeighborhoodStates, bool>({0, 0, 1}, 1),
                                         std::make_pair<CellNeighborhoodStates, bool>({0, 1, 0}, 1),
                                         std::make_pair<CellNeighborhoodStates, bool>({0, 1, 1}, 1),
                                         std::make_pair<CellNeighborhoodStates, bool>({1, 0, 0}, 1),
                                         std::make_pair<CellNeighborhoodStates, bool>({1, 0, 1}, 0),
                                         std::make_pair<CellNeighborhoodStates, bool>({1, 1, 0}, 0),
                                         std::make_pair<CellNeighborhoodStates, bool>({1, 1, 1}, 0)));


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}