#include "GUI/src/initial_cell_state.h"
#include "GUI/src/config.h"
#include "GUI/src/cell_state_visualization.h"

#include "ThirdParty/imgui/imgui.h"

#include <algorithm>

InitialCellState::InitialCellState(const std::bitset<8> &initial_cell_state)
	: initial_cell_state_(initial_cell_state) {}

void InitialCellState::Show()
{
  ImGui::SetNextWindowPos(Config::InitialCellState::ORIGIN);
  ImGui::SetNextWindowSize(Config::InitialCellState::SIZE);
  ImGui::Begin("Initial cell state");
  for (std::size_t i{0}; i < initial_cell_state_.size(); i++)
  {
	ImGui::PushID(i);
	CellState::Visualize(initial_cell_state_[i]);
	ImGui::PopID();
	ImGui::SameLine(0.0, 0.0);
  }
  ImGui::End();
}
