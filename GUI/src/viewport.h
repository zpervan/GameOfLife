#ifndef GAMEOFLIFE_VIEWPORT_H
#define GAMEOFLIFE_VIEWPORT_H

#include "GUI/src/grid.h"
#include "Simulator/src/cellular_automata_algorithm.h"
#include <SFML/Graphics.hpp>

/// @brief Represents the screen area in which the simulator will show the output from the cellular automaton
/// algorithm.
/// @tableofcontents Containts:
/// * Grid
class Viewport {
public:
    explicit Viewport(sf::RenderWindow &window);

    void SetGridSize(std::size_t row, std::size_t column);

    void SetCellState(bool new_cell_state, std::size_t row, std::size_t column);

    void Show();

private:
    sf::RenderWindow &window_;
    std::unique_ptr<Grid> grid_;
    std::unique_ptr<std::vector<sf::RectangleShape>> grid_shapes_;
    std::unique_ptr<std::vector<sf::RectangleShape>> cell_states_;
};

#endif //GAMEOFLIFE_VIEWPORT_H
