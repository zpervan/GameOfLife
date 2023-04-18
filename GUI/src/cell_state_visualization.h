#ifndef GAMEOFLIFE_GUI_SRC_CELL_STATE_VISUALIZATION_H_
#define GAMEOFLIFE_GUI_SRC_CELL_STATE_VISUALIZATION_H_

#include <imgui-SFML.h>

#include "GUI/src/assets.h"
#include "GUI/src/config.h"

namespace CellState
{
/// @brief Visualizes the cell state.
/// @param cell_state Current state of a cell
inline void Visualize(bool cell_state, float cell_size = Config::Cell::SIZE)
{
    if (cell_state == 0)
    {
        ImGui::Image(*Assets::GetBlackCell(), {cell_size, cell_size}, sf::Color::White, sf::Color::Blue);
    }
    else
    {
        ImGui::Image(*Assets::GetWhiteCell(), {cell_size, cell_size}, sf::Color::White, sf::Color::Blue);
    }
}

}  // namespace CellState

#endif  // GAMEOFLIFE_GUI_SRC_CELL_STATE_VISUALIZATION_H_
