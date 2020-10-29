#ifndef GAMEOFLIFE_GUI_SRC_CELL_STATE_VISUALIZATION_H_
#define GAMEOFLIFE_GUI_SRC_CELL_STATE_VISUALIZATION_H_

#include "GUI/src/assets.h"
#include "GUI/src/config.h"
#include "ThirdParty/imgui/imgui-SFML.h"

namespace CellState
{
	inline void Visualize(bool cell_state)
	{
	  if (cell_state == 0)
	  {
		ImGui::Image(*Assets::GetBlackCell(), Config::RulePreview::CELL_SIZE, sf::Color::White, sf::Color::Green);
	  } else
	  {
		ImGui::Image(*Assets::GetWhiteCell(), Config::RulePreview::CELL_SIZE, sf::Color::White, sf::Color::Green);
	  }
	}
}

#endif //GAMEOFLIFE_GUI_SRC_CELL_STATE_VISUALIZATION_H_
