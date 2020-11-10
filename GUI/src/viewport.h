#ifndef GAMEOFLIFE_VIEWPORT_H
#define GAMEOFLIFE_VIEWPORT_H

#include "GUI/src/grid.h"
#include "Simulator/src/data.h"
#include <SFML/Graphics.hpp>
#include <deque>
#include <vector>

using CellGridRowStates = std::vector<sf::RectangleShape>;
using CellGridStates = std::deque<CellGridRowStates>;

/// @brief Represents the screen area in which the simulator will show the output from the cellular automaton algorithm.
class Viewport {
public:
    /// @brief Set the number of rows and columns of the grid.
    /// @param row Number of rows
    /// @param column Number of columns
    void SetGridSize(std::size_t row, std::size_t column);

    /// @brief Initialize the grid and cell states of the viewport.
    void Initialize();

    /// @brief Updates the cell state for given row and column position in the viewport screen space.
    /// @param new_cell_state State of the cell in the new generation
    /// @param row_position Row position of the cell which shall be updated in the new cell generation
    /// @param column_position Column position of the cell which shall be updated in the new cell generation
    void SetCellState(bool new_cell_state, std::size_t row_position, std::size_t column_position);

    /// @brief Removing the oldest (first) cell generation when ETERNAL simulation mode is used.
    void RemoveOldestGeneration();

    void ShiftCellPositionUp(sf::RectangleShape &cell);

    void SetSimulationMode(SimulationMode simulation_mode);

    void AddNewCellGeneration();

    /// @brief Toggle the grid display.
    /// @param show Toggle the grid ON or OFF
    void ShowGrid(bool show);

    /// @brief Displays the viewport.
    void Show();

    /// Parametrized constructor
    explicit Viewport(sf::RenderWindow &window);

private:
    void CreateGrid();

    void InitializeCellGridStates();

    sf::RenderWindow &window_;
    std::unique_ptr<Grid> grid_;
    std::unique_ptr<std::vector<sf::RectangleShape>> grid_shapes_;
    std::unique_ptr<CellGridStates> cell_grid_states_;
    SimulationMode simulation_mode_;
    uint row_;
    uint column_;

    bool show_grid_{false};
};

#endif //GAMEOFLIFE_VIEWPORT_H
