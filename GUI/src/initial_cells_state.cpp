#include "GUI/src/initial_cells_state.h"

#include <imgui.h>

#include "GUI/src/cell_state_visualization.h"
#include "GUI/src/config.h"
#include "GUI/src/utility.h"

void InitialCellGenerationStateWindow::UpdateInitialCellGenerationState(
    const std::vector<bool>& initial_cell_generation_states)
{
    initial_cell_generation_states_ = initial_cell_generation_states;
    column_size_ = initial_cell_generation_states.size();
}

void InitialCellGenerationStateWindow::Show()
{
    ImGui::SetNextWindowPos(Config::InitialCellsState::ORIGIN);
    ImGui::SetNextWindowSize(Config::InitialCellsState::SIZE);
    ImGui::Begin("Initial cell state");

    if (!initial_cell_generation_states_.empty())
    {
        CalculateCellSize();
        CalculateStartPosition();
        VisualizeInitialCellsState();
    }
    else
    {
        ImGui::Text("Create a initial cell generation by setting the grid size and define cell states!");
    }

    ImGui::End();
}

void InitialCellGenerationStateWindow::CalculateCellSize()
{
    while (Utility::IsCellSizeExceedingWindowSize(column_size_, cell_size_, Config::InitialCellsState::WIDTH))
    {
        cell_size_ -= 0.1;
    }
}

void InitialCellGenerationStateWindow::CalculateStartPosition()
{
    const auto horizontal_half_screen_size{Config::InitialCellsState::WIDTH / 2.0f};
    horizontal_start_position_ =
        Utility::CalculateHorizontalStartPosition(cell_size_, column_size_, horizontal_half_screen_size);
}

void InitialCellGenerationStateWindow::VisualizeInitialCellsState() const
{
    for (std::size_t i{0}; i < initial_cell_generation_states_.size(); i++)
    {
        ImGui::PushID(i);
        ImGui::SameLine(horizontal_start_position_ + (cell_size_ * i), Config::Flag::NO_SPACING);
        CellState::Visualize(initial_cell_generation_states_.at(i), cell_size_);
        ImGui::PopID();
    }
}
