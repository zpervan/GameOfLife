#include "GUI/src/rule_preview.h"

#include "GUI/src/config.h"
#include "GUI/src/cell_state_visualization.h"

#include "ThirdParty/imgui/imgui.h"
#include "ThirdParty/fmt/include/fmt/core.h"

RulePreview::RulePreview(std::pair<std::string, std::bitset<8>> &current_rule) : current_rule_(current_rule) {}

void RulePreview::Show()
{
  ImGui::SetNextWindowPos(Config::RulePreview::ORIGIN);
  ImGui::SetNextWindowSize(Config::RulePreview::SIZE);
  ImGui::Begin("Rule preview");

  ImGui::Text("%s", fmt::format("Selected: {}", current_rule_.first).c_str());
  ImGui::NewLine();
  ImGui::NewLine();

  for (std::size_t row{0}; row <= 3; row++)
  {
	if (row == 0) CreateCurrentPatternCellGroupRow(0, 3);
	if (row == 1) CreateNewStateCellRow(0, 3);
	if (row == 2) CreateCurrentPatternCellGroupRow(4, 7);
	if (row == 3) CreateNewStateCellRow(4, 7);
	ImGui::NewLine();
  }
  ImGui::End();
}

void RulePreview::CreateCurrentPatternCellGroup(const std::size_t cell_group_index)
{
  float cell_offset{0.0};

  std::bitset<3> cell_group_index_in_binary{cell_group_index};
  for (std::size_t i{0}; i <= 2; i++)
  {
	if (i == 0)
	{
	  cell_offset = CalculateCurrentPatternCellGroupStartXPosition(cell_group_index);
	}

	ImGui::SameLine(cell_offset += Config::RulePreview::CELL_SIZE.x, 0.0f);
	ImGui::PushID(i);
	CellState::Visualize(cell_group_index_in_binary[i]);
	ImGui::PopID();
  }
}

void RulePreview::CreateNewStateCell(const std::size_t cell_index)
{
  const float cell_offset = CalculateNewStateCellXPosition(cell_index);

  ImGui::SameLine(cell_offset, 0.0f);
  ImGui::PushID(cell_index);
  CellState::Visualize(current_rule_.second[cell_index]);
  ImGui::PopID();
}

float RulePreview::CalculateCurrentPatternCellGroupStartXPosition(std::size_t cell_group_element_index)
{
  constexpr uint8_t last_cell_group_element_index{4};
  if (cell_group_element_index >= last_cell_group_element_index)
  {
	cell_group_element_index -= 4;
  }
  return Config::RulePreview::CELL_GROUP_OFFSET * cell_group_element_index;
}

float RulePreview::CalculateNewStateCellXPosition(std::size_t cell_element_index)
{
  if (cell_element_index > 3)
  {
	cell_element_index -= 4;
  }
  return cell_element_index == 0 ? Config::RulePreview::NEW_STATE_CELL_OFFSET :
		 Config::RulePreview::NEW_STATE_CELL_OFFSET + (Config::RulePreview::CELL_GROUP_OFFSET * cell_element_index);
}

void RulePreview::CreateCurrentPatternCellGroupRow(std::size_t start_index, std::size_t end_index)
{
  for (; start_index <= end_index; start_index++)
  {
	CreateCurrentPatternCellGroup(start_index);
  }
}

void RulePreview::CreateNewStateCellRow(std::size_t start_index, std::size_t end_index)
{
  for (; start_index <= end_index; start_index++)
  {
	CreateNewStateCell(start_index);
  }
  ImGui::NewLine();
}
