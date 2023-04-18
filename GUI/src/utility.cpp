#include "GUI/src/utility.h"

#include <imgui.h>

#include <chrono>
#include <cinttypes>
#include <cstdlib>

namespace Utility
{
void AddVerticalSpacing(const std::size_t count)
{
    for (std::size_t i{0}; i < count; i++)
        ImGui::NewLine();
}

uint GenerateRandomNumberInRange(const uint start, const uint end)
{
    assert((start < end) && "Start has a greater value then end, but it shouldn't be!");
    assert((start > 0) || (end > 0) && "Start or end number is negative, but shouldn't be!");

    time_t timer;
    srandom(time(&timer));
    return (random() % (start + 1 - end)) + end;
}

void HelpMarker(const std::string& description)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(description.c_str());
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

float CalculateHorizontalStartPosition(float cell_size, std::size_t column_size, float half_screen_width)
{
    float horizontal_half_row_cells_dimension{cell_size * (column_size / 2.0f)};
    return half_screen_width - horizontal_half_row_cells_dimension;
}

float CalculateVerticalStartPosition(float cell_size, std::size_t row_size, float half_screen_height)
{
    float vertical_half_grid_size{cell_size * (row_size / 2.0f)};
    return half_screen_height - vertical_half_grid_size;
}

bool IsCellSizeExceedingWindowSize(std::size_t grid_component_size, float cell_size, float window_dimension)
{
    return (grid_component_size * cell_size) > window_dimension;
}
}  // namespace Utility