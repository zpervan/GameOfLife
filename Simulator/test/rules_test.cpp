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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}