#include "Simulator/src/cellular_automata_algorithm.h"

#include "Simulator/test/test_utility.h"
#include "gtest/gtest.h"

class CellularAutomataAlgorithmGenerateTestFixture : public ::testing::Test
{
  protected:
    const std::bitset<8> default_rule_{30};
};

TEST_F(CellularAutomataAlgorithmGenerateTestFixture, GivenInitialCellState_WhenGeneratingNewCellState_ThenGeneratedNewCellStateIsCorrect)
{
    const std::vector<std::vector<bool>> expected_new_cell_generations{
        {0, 1, 0, 1, 1, 1, 1, 0}, {1, 1, 0, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 1, 1}};
    const std::vector<bool> initial_cell_generation{0, 1, 0, 1, 0, 0, 1, 1};

    CellularAutomataAlgorithm algorithm;
    algorithm.SetRule(default_rule_);
    algorithm.SetInitialCellGenerationState(initial_cell_generation);

    for (std::size_t row{0}; row < expected_new_cell_generations.size(); row++)
    {
        for (std::size_t column{0}; column < expected_new_cell_generations[row].size(); column++)
        {
            const auto& actual_new_cell_state{algorithm.CreateNewCellState(column)};
            EXPECT_EQ(actual_new_cell_state.value(), expected_new_cell_generations[row][column])
                << fmt::format("Failed at row {} and column {}", row, column);
        }
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}