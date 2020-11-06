#include "GUI/src/initial_cells_state.h"

#include "GUI/src/cell_state_visualization.h"
#include "GUI/src/config.h"
#include "ThirdParty/imgui/imgui.h"
#include <algorithm>

void InitialCellsStateWindow::UpdateInitialCellStates(const std::vector<bool> &initial_cell_states) {
    initial_cell_states_ = initial_cell_states;
}

void InitialCellsStateWindow::Show() {
    ImGui::SetNextWindowPos(Config::InitialCellsState::ORIGIN);
    ImGui::SetNextWindowSize(Config::InitialCellsState::SIZE);
    ImGui::Begin("Initial cell state");

    if (!initial_cell_states_.empty()) {
        VisualizeInitialCellsState();
    } else {
        ImGui::Text("Create a initial cell generation by setting the grid size and define cell states!");
    }

    ImGui::End();
}

void InitialCellsStateWindow::VisualizeInitialCellsState() const {
    for (std::size_t i{0}; i < initial_cell_states_.size(); i++) {
        ImGui::PushID(i);
        ImGui::SameLine(CalculateCellXPosition(i), Config::Flag::NO_SPACING);
        CellState::Visualize(initial_cell_states_.at(i));
        ImGui::PopID();
    }
}

float InitialCellsStateWindow::CalculateCellXPosition(const std::size_t i) const {
    return Config::InitialCellsState::HORIZONTAL_OFFSET + (Config::Cell::SIZE.x * i);
}
