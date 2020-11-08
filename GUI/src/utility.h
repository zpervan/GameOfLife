#ifndef GAMEOFLIFE_UTILITY_H
#define GAMEOFLIFE_UTILITY_H

#include "ThirdParty/imgui/imgui.h"
#include <string>
#include <cstdlib>
#include <cinttypes>
#include <chrono>

namespace Utility {
    inline void AddVerticalSpacing(std::size_t count) {
        for (std::size_t i{0}; i < count; i++)
            ImGui::NewLine();
    }

    /// @attention If we pass a negative number, that number will overflow. As we are dealing with randomness, this is
    /// OK for the end range, but if the range start overflows it will probably hit an assert!
    inline uint GenerateRandomNumberInRange(uint start, uint end) {
        assert((start < end) && "Start has a greater value then end, but it shouldn't be!");
        assert((start > 0) || (end > 0) && "Start or end number is negative, but shouldn't be!");

        time_t timer;
        srandom(time(&timer));
        return (random() % (start + 1 - end)) + end;
    }

    inline void HelpMarker(const std::string &description) {
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered()) {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(description.c_str());
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }
}

#endif //GAMEOFLIFE_UTILITY_H
