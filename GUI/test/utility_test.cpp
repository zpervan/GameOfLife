#include "GUI/src/utility.h"

#include "ThirdParty/fmt/include/fmt/core.h"
#include "gtest/gtest.h"

/// @attention As we are testing randomness without a seed, generate a random number 1000 times and ensure that the
/// value is always between 0 and 255
TEST(UtilityTest, GivenValidStartAndEndRange_WhenGeneratingRandomNumber_ThenGeneratedNumberInRange)
{
    constexpr uint8_t range_start{0};
    constexpr uint8_t range_end{255};

    for (std::size_t i{0}; i < 1000; i++)
    {
        const uint8_t generated_number = Utility::GenerateRandomNumberInRange(range_start, range_end);

        EXPECT_GE(generated_number, 0);
        EXPECT_LE(generated_number, 255);
    }
}

class UtilityDeathTestFixture : public testing::TestWithParam<std::pair<uint8_t, uint8_t>>
{
};

TEST_P(UtilityDeathTestFixture, GivenInvalidStartAndEndRange_WhenGeneratingNumber_ThenAssertIsThrown)
{
    const auto& [range_start, range_end] = GetParam();

    ASSERT_DEATH(Utility::GenerateRandomNumberInRange(range_start, range_end), ".*");
}

INSTANTIATE_TEST_SUITE_P(UtilityParametrizedDeathTest,
                         UtilityDeathTestFixture,
                         testing::Values(std::make_pair<uint8_t, uint8_t>(-1, 0),
                                         std::make_pair<uint8_t, uint8_t>(255, 0),
                                         std::make_pair<uint8_t, uint8_t>(100, 100)));

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}