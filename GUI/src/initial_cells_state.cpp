#include "GUI/src/initial_cells_state.h"

#include "GUI/src/cell_state_visualization.h"
#include "ThirdParty/imgui/imgui.h"
#include <algorithm>

InitialCellsState::InitialCellsState(const std::bitset<8> &initial_cell_state)
        : initial_cell_state_(initial_cell_state) {}

void InitialCellsState::Show() {
    ImGui::SetNextWindowPos(Config::InitialCellsState::ORIGIN);
    ImGui::SetNextWindowSize(Config::InitialCellsState::SIZE);
    ImGui::Begin("Initial cell state");

    VisualizeInitialCellsState();

    ImGui::End();
}

void InitialCellsState::VisualizeInitialCellsState() const {
    for (std::size_t i{0}; i < initial_cell_state_.size(); i++) {
        ImGui::PushID(i);
        ImGui::SameLine(CalculateCellXPosition(i), Config::Flag::NO_SPACING);
        CellState::Visualize(initial_cell_state_[i]);
        ImGui::PopID();
    }
}

float InitialCellsState::CalculateCellXPosition(const std::size_t i) const {
    return Config::InitialCellsState::HORIZONTAL_OFFSET + (Config::Cell::SIZE.x * i);
}
