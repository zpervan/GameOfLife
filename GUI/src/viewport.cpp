#include "GUI/src/viewport.h"
#include <thread>
#include <chrono>

Viewport::Viewport(sf::RenderWindow &window) : window_(window), grid_(new Grid) {}

void Viewport::SetGridSize(std::size_t row, std::size_t column) {
    grid_->SetGridSize(row, column);
    grid_shapes_ = std::make_unique<std::vector<sf::RectangleShape>>(grid_->CreateGrid());
    cell_states_ = std::make_unique<std::forward_list<sf::RectangleShape>>();
}

void Viewport::SetCellState(bool new_cell_state, std::size_t row_position, std::size_t column_position) {
    const auto &updated_cell_state{grid_->UpdateCellState(new_cell_state, row_position, column_position)};
    cell_states_->emplace_after(cell_states_->before_begin(), updated_cell_state);
}

void Viewport::RemoveOldestGeneration() {
    auto oldest_generation_begin{cell_states_->before_begin()};
    auto oldest_generation_end{std::next(oldest_generation_begin, grid_->GetGridSize().column)};
    cell_states_->erase_after(oldest_generation_begin, oldest_generation_end);
}

void Viewport::ShiftCellPositionUp(sf::RectangleShape &cell) {
    auto[x, y] = cell.getPosition();
    const auto shifted_y_position{y -= grid_->GetGridCellSize()};
    cell.setPosition(x, shifted_y_position);
}

void Viewport::ShowGrid(bool show) {
    show_grid_ = show;
}

void Viewport::Show() {
    window_.clear(sf::Color::White);

    for (auto &cell_state : *cell_states_) {
//        if (simulation_mode_) ShiftCellPositionUp(cell_state);
        window_.draw(cell_state);
    }

    if (show_grid_) {
        for (const auto &grid : *grid_shapes_) {
            window_.draw(grid);
        }
    }

    std::this_thread::sleep_for(std::chrono::microseconds(1000));
}

void Viewport::SetSimulationMode(SimulationMode simulation_mode) {
    simulation_mode_ = simulation_mode;
}
