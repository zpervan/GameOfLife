#include "GUI/src/viewport.h"

#include <chrono>
#include <thread>

Viewport::Viewport(sf::RenderWindow& window) : window_(window) {}

void Viewport::SetGridSize(std::size_t row, std::size_t column)
{
    grid_ = std::make_unique<Grid>();
    row_ = row;
    column_ = column;
}

void Viewport::Initialize()
{
    CreateGrid();
    InitializeCellGridStates();
}

void Viewport::InitializeCellGridStates()
{
    CellGridRowStates cell_grid_row_states;
    cell_grid_row_states.reserve(column_);

    cell_grid_states_ = std::make_unique<CellGridStates>();
    cell_grid_states_->emplace_back(std::move(cell_grid_row_states));
}

void Viewport::SetCellState(bool new_cell_state, std::size_t row_position, std::size_t column_position)
{
    auto updated_cell_state{grid_->UpdateCellState(new_cell_state, row_position, column_position)};
    cell_grid_states_->at(row_position).emplace_back(std::move(updated_cell_state));
}

void Viewport::AddNewCellGeneration()
{
    CellGridRowStates cell_grid_row_states;
    cell_grid_row_states.reserve(column_);
    cell_grid_states_->emplace_back(std::move(cell_grid_row_states));
}

void Viewport::RemoveOldestGeneration()
{
    cell_grid_states_->pop_front();
}

void Viewport::Show()
{
    window_.clear(sf::Color::White);

    ShowCellGridStates();
    ShowGrid();

    std::this_thread::sleep_for(std::chrono::microseconds(1000));
}

void Viewport::ShowGrid() const
{
    if (show_grid_)
    {
        for (const auto& grid : *grid_shapes_)
        {
            window_.draw(grid);
        }
    }
}

void Viewport::ShowCellGridStates()
{
    for (auto& cell_row_states : *cell_grid_states_)
    {
        for (auto& cell_state : cell_row_states)
        {
            window_.draw(cell_state);
        }
    }
    AddNewCellGeneration();
}

void Viewport::ShiftCellsPositionUp()
{
    for (auto& cell_row : *cell_grid_states_)
    {
        for (auto& cell : cell_row)
        {
            auto [x, y] = cell.getPosition();
            const auto shifted_y_position{y -= grid_->GetGridCellSize()};
            cell.setPosition(x, shifted_y_position);
        }
    }
}

void Viewport::CreateGrid()
{
    grid_->SetGridSize(row_, column_);
    grid_shapes_ = std::make_unique<std::vector<sf::RectangleShape>>(grid_->CreateGrid());
}

void Viewport::ShowGrid(bool show)
{
    show_grid_ = show;
}
