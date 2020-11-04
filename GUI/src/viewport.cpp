#include "GUI/src/viewport.h"
#include <thread>
#include <chrono>

Viewport::Viewport(sf::RenderWindow &window) : window_(window), grid_(new Grid) {
    grid_->SetGridSize(50, 50);
    grid_shapes_ = std::make_unique<std::vector<sf::RectangleShape>>(grid_->CreateGrid());
    cell_states_ = std::make_unique<std::vector<sf::RectangleShape>>();
}

void Viewport::Show() {
    window_.clear(sf::Color::White);

    if (counter < 22) {
        std::vector<std::vector<bool>> cell_statez{{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
                                                   {1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}};
        cell_states_->emplace_back(grid_->UpdateCellState(cell_statez[0][counter], 0, counter));
        cell_states_->emplace_back(grid_->UpdateCellState(cell_statez[1][counter], 1, counter));
        counter++;
    }

    for (const auto &cell_state : *cell_states_) {
        window_.draw(cell_state);
    }

    for (const auto &grid : *grid_shapes_) {
        window_.draw(grid);
    }
    std::this_thread::sleep_for(std::chrono::microseconds(10000));
}
