#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include "GUI/src/config.h"
#include <SFML/Graphics.hpp>

class Grid {
public:
    /// @brief Sets the grid size if the range is valid.
    /// @throws If row value is smaller than 1 or column value is smaller than 3.
    void SetGridSize(uint row, uint column);

    /// @brief Creates the basic shape layout for the given grid size.
    std::vector<sf::RectangleShape> CreateGrid();

private:
    void CalculateGridCellSize();

    void CalculateLineThickness();

    void CreateHorizontalGrid();

    void CreateVerticalGrid();

    void CalculateHorizontalGridStartPosition();

    void CalculateVerticalGridStartPosition();

    bool IsGridLargerThanViewportScreen() const;

    const uint minimum_row_size_{1};
    const uint minimum_column_size_{3};
    const uint maximum_size_{300};

    const float horizontal_center_point_{Config::Viewport::SCREEN_SIZE.x / 2};
    const float vertical_center_point_{Config::Viewport::SCREEN_SIZE.y / 2};

    std::vector<sf::RectangleShape> grid_shapes_;
    sf::Vector2u grid_size_{20, 15};
    float grid_cell_size_{80.0};
    float line_thickness_{2.0};
    float horizontal_start_position_{0.0};
    float vertical_start_position_{0.0};
};


#endif //GAMEOFLIFE_GRID_H
