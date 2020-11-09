#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include "GUI/src/config.h"
#include <SFML/Graphics.hpp>

/// @brief A helper structure which represents the grid size.
struct GridSize {
    uint row;
    uint column;
};

/// @brief Contains logic for creating a scalable grid size inside the viewport/canvas. Each grid cell can have a state
/// - ON (white) or OFF (black).
class Grid {
public:
    /// @brief Sets the grid size if the row and column ranges are valid.
    /// @param row Number of rows in the grid
    /// @param column Number of columns in the grid
    /// @throws Row value is smaller than 1 or larger than 300
    /// @throws Column value is smaller than 3 or greater than 300
    void SetGridSize(uint row, uint column);

    /// @brief Creates the basic shape layout for the given grid size.
    std::vector<sf::RectangleShape> CreateGrid();

    /// @brief Updates the cell state (ON/OFF) at the specific row and column position.
    /// @param cell_state Can be ON (black) or OFF (white)
    /// @param row Row position of the cell which shall be updated
    /// @param column Column position of the cell which shall be updated
    /// @return A rectangle shape which represents the state of the grid cell located at given position
    sf::RectangleShape UpdateCellState(bool cell_state, uint row, uint column);

    /// Getters

    GridSize GetGridSize() const;

    float GetGridCellSize() const;

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
