#include "GUI/src/viewport.h"
#include <thread>
#include <chrono>

Viewport::Viewport(sf::RenderWindow &window) : window_(window), grid_(new Grid) {

}

void Viewport::SetGridSize(std::size_t row, std::size_t column) {
    grid_->SetGridSize(row, column);
    grid_shapes_ = std::make_unique<std::vector<sf::RectangleShape>>(grid_->CreateGrid());
    cell_states_ = std::make_unique<std::vector<sf::RectangleShape>>();
}

void Viewport::SetCellState(bool new_cell_state, std::size_t row, std::size_t column) {
    cell_states_->emplace_back(grid_->UpdateCellState(new_cell_state, row, column));
}

void Viewport::Show() {
    window_.clear(sf::Color::White);

    for (const auto &cell_state : *cell_states_) {
        window_.draw(cell_state);
    }

    for (const auto &grid : *grid_shapes_) {
        window_.draw(grid);
    }
    std::this_thread::sleep_for(std::chrono::microseconds(10));
}
