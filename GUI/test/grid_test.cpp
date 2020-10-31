#include "GUI/src/grid.h"

#include "ThirdParty/fmt/include/fmt/core.h"
#include "gtest/gtest.h"

class GridSizeExceptionTestFixture : public testing::TestWithParam<std::pair<uint, uint>> {
protected:
    Grid grid_;
};

TEST_P(GridSizeExceptionTestFixture, GivenGridSizeIsNotValid_WhenSettingGridSize_ThenExceptionIsThrown) {
    const auto &[row, column] = GetParam();
    EXPECT_THROW(grid_.SetGridSize(row, column), std::invalid_argument);
}

INSTANTIATE_TEST_SUITE_P(GridSizeParametrizedExceptionTest, GridSizeExceptionTestFixture,
                         testing::Values(std::make_pair<uint, uint>(0, 3),
                                         std::make_pair<uint, uint>(1, 2),
                                         std::make_pair<uint, uint>(0, 2),
                                         std::make_pair<uint, uint>(300, 301),
                                         std::make_pair<uint, uint>(301, 300),
                                         std::make_pair<uint, uint>(301, 301)));


class GridTestFixture : public testing::Test {
protected:
    Grid grid_;
    const uint minimum_row_size_{1};
    const uint minimum_column_size_{3};
    const uint maximum_row_size_{300};
    const uint maximum_column_size_{300};
};

TEST_F(GridTestFixture,
       GivenValidRowAndColumnSize_WhenCalculatingLineThickness_ThenLineThicknessIsCorrect) {
    const std::array<float, 2> expected_line_thickness{2.0, 1.0};
    const std::array<sf::Vector2u, 2> grid_size{{{1, 20}, {21, 3}}};

    for (std::size_t i{0}; i < expected_line_thickness.size(); ++i) {
        Grid grid;
        grid.SetGridSize(grid_size[i].x, grid_size[i].y);
        const auto &actual_grid_shapes{grid.CreateGrid()};
        EXPECT_FLOAT_EQ(actual_grid_shapes[0].getSize().y, expected_line_thickness[i])
                            << fmt::format("Failed at row {} and column {}", grid_size[i].x, grid_size[i].y);
    }

}


TEST_F(GridTestFixture, GivenMinimumValidRowAndColumnSize_WhenCreatingGrid_ThenGridShapeSizeIsCorrect) {
    const std::size_t expected_size_of_grid_shapes{minimum_row_size_ + minimum_column_size_ + 2};

    grid_.SetGridSize(minimum_row_size_, minimum_column_size_);

    const auto &actual_grid_shapes{grid_.CreateGrid()};

    EXPECT_EQ(actual_grid_shapes.size(), expected_size_of_grid_shapes);
}

TEST_F(GridTestFixture, GivenMaximumValidRowAndColumnSize_WhenCreatingGrid_ThenGridShapeSizeIsCorrect) {
    const std::size_t expected_size_of_grid_shapes{maximum_row_size_ + maximum_column_size_ + 2};

    grid_.SetGridSize(maximum_row_size_, maximum_column_size_);

    const auto &actual_grid_shapes{grid_.CreateGrid()};

    EXPECT_EQ(actual_grid_shapes.size(), expected_size_of_grid_shapes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}