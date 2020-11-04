#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include "GUI/src/config.h"
#include <SFML/Graphics.hpp>
#include <bitset>

/// @brief A helper structure which represents a grid size
struct GridSize {
    uint row;
    uint column;
};

class Grid {
public:
    /// @brief Sets the grid size if the range is valid.
    /// @throws If row value is smaller than 1 or column value is smaller than 3
    /// @throws If row and column value are greater than 300
    void SetGridSize(uint row, uint column);

    /// @brief Creates the basic shape layout for the given grid size.
    std::vector<sf::RectangleShape> CreateGrid();

    sf::RectangleShape UpdateCellState(bool cell_state, std::size_t row, std::size_t column);

private:
    void CalculateGridCellSize();

    void CalculateLineThickness();

    void CreateHorizontalGrid();

    void CreateVerticalGrid();

    void CalculateHorizontalGridStartPosition();

    void CalculateVerticalGridStartPosition();

    bool IsGridLargerThanViewportScreen() const;

    sf::Vector2f CalculateCellStatePosition(uint row, uint column) const;

    const uint minimum_row_size_{1};
    const uint minimum_column_size_{3};
    const uint maximum_size_{300};

    const float horizontal_center_point_{Config::Viewport::SCREEN_SIZE.x / 2};
    const float vertical_center_point_{Config::Viewport::SCREEN_SIZE.y / 2};

    std::vector<sf::RectangleShape> grid_shapes_;
    GridSize grid_size_{0, 0};
    float grid_cell_size_{80.0};
    float line_thickness_{2.0};
    float horizontal_start_position_{0.0};
    float vertical_start_position_{0.0};
};


#endif //GAMEOFLIFE_GRID_H
