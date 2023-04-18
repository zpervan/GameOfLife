#ifndef GAMEOFLIFE_UTILITY_H
#define GAMEOFLIFE_UTILITY_H

#include <string>

namespace Utility
{
/// @brief Wrapper function around ImGui::NewLine() which adds vertical spacing to GUI components.
void AddVerticalSpacing(std::size_t count);

/// @brief Generates a random number between a given range.
/// @attention If we pass a negative number, that number will overflow. As we are dealing with randomness, this is
/// OK for the end range, but if the range start overflows it will probably hit an assert!
uint GenerateRandomNumberInRange(uint start, uint end);

/// @brief Creates a tooltip window which contains additional information about functionalities shown in the GUI.
/// @param description Message which will be displayed in the tooltip window
void HelpMarker(const std::string& description);

/// @brief Checks if the cell row or column size (grid component size) is exceeding the window size.
/// @param grid_component_size Represents the row or column size
/// @param cell_size Cell size
/// @param window_dimension Value against the grid component size will be compared
/// @return If true, the current grid component size is exceeding the window dimension
bool IsCellSizeExceedingWindowSize(std::size_t grid_component_size, float cell_size, float window_dimension);

/// @brief Calculates the horizontal start position for given row.
/// @param cell_size Size of the cell
/// @param column_size Column size
/// @param half_screen_width Half of the width on the currently processed screen space
/// @return Horizontal start position
float CalculateHorizontalStartPosition(float cell_size, std::size_t column_size, float half_screen_width);

/// @brief Calculates the vertical start position for given row.
/// @param cell_size Size of the cell
/// @param row_size Row size
/// @param half_screen_height Half of the height on the currently processed screen space
/// @return Vertical start position
float CalculateVerticalStartPosition(float cell_size, std::size_t row_size, float half_screen_height);
}  // namespace Utility

#endif  // GAMEOFLIFE_UTILITY_H
