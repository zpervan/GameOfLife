#ifndef GAMEOFLIFE_GUI_SRC_RULE_PREVIEW_H_
#define GAMEOFLIFE_GUI_SRC_RULE_PREVIEW_H_

#include "Simulator/src/data.h"

#include "GUI/src/assets.h"
#include "ThirdParty/imgui/imgui.h"
#include "ThirdParty/imgui/imgui-SFML.h"
#include "ThirdParty/fmt/include/fmt/core.h"

#include <SFML/Graphics.hpp>

namespace RulePreview
{
	void CreateCellPattern(std::size_t pattern_number);

	void Show()
	{
	  ImGui::SetNextWindowPos(Config::RulePreview::ORIGIN);
	  ImGui::SetNextWindowSize(Config::RulePreview::SIZE);
	  ImGui::Begin("Rule preview");

	  ImGui::Text("%s", fmt::format("Selected: {}", Data::current_rule.first).c_str());
	  ImGui::NewLine();

	  for (std::size_t i{0}; i <= 7; i++)
	  {
		CreateCellPattern(i);
	  }

	  ImGui::End();
	}

	float CalculateCellGroupStartXPosition(float value)
	{
	  constexpr float offset{190.0};
	  if (value >= 4)
	  {
		value -= 4;
	  }
	  return offset * value;
	}

	void CreateCellPattern(std::size_t pattern_number)
	{
	  float cell_offset{0.0};

	  if (pattern_number == 4)
	  {
		ImGui::NewLine();
		ImGui::NewLine();
		ImGui::NewLine();
	  }

	  std::bitset<3> binary_pattern_number{pattern_number};
	  for (std::size_t i{0}; i <= 2; i++)
	  {
		if (i == 0)
		{
		  cell_offset = CalculateCellGroupStartXPosition(pattern_number);
		}

		ImGui::SameLine(cell_offset += 40, 0.0f);

		ImGui::PushID(i);

		if (binary_pattern_number[i] == 0)
		{
		  ImGui::Image(*Assets::GetBlackCell(), {40, 40}, sf::Color::White, sf::Color::Green);
		} else
		{
		  ImGui::Image(*Assets::GetWhiteCell(), {40, 40}, sf::Color::White, sf::Color::Green);
		}

		ImGui::PopID();
	  }
	}
}

#endif //GAMEOFLIFE_GUI_SRC_RULE_PREVIEW_H_
