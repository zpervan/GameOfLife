#include "GUI/src/viewport.h"

Viewport::Viewport(sf::RenderWindow &window) : window_(window) {
    Grid grid;
    grid_shapes_ = std::make_unique<std::vector<sf::RectangleShape>>(grid.CreateGrid());
}

void Viewport::Show() {
    window_.clear(sf::Color::White);
    for (const auto &grid_shape : *grid_shapes_) {
        window_.draw(grid_shape);
    }
}
