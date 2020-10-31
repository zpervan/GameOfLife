#ifndef GAMEOFLIFE_VIEWPORT_H
#define GAMEOFLIFE_VIEWPORT_H

#include "GUI/src/grid.h"
#include <SFML/Graphics.hpp>

/// @brief Represents the screen area in which the simulator will show the output from the cellular automaton
/// algorithm.
/// @tableofcontents Containts:
/// * Grid
class Viewport {
public:
    explicit Viewport(sf::RenderWindow &window);

    void Show();

private:
    sf::RenderWindow &window_;
    std::unique_ptr<std::vector<sf::RectangleShape>> grid_shapes_;;
};

#endif //GAMEOFLIFE_VIEWPORT_H
