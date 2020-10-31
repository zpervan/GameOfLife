#ifndef GAMEOFLIFE_UTILITY_H
#define GAMEOFLIFE_UTILITY_H

#include "ThirdParty/imgui/imgui.h"
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
    inline uint8_t GenerateRandomNumberInRange(uint8_t start, uint8_t end) {
        assert((start < end) && "Start has a greater value then end, but it shouldn't be!");
        assert((start < 255) || (end < 255) && "Start or end number is greater than 255, but shouldn't be!");
        assert((start > 0) || (end > 0) && "Start or end number is negative, but shouldn't be!");

        time_t timer;
        srandom(time(&timer));
        return (random() % (start + 1 - end)) + end;
    }
}

#endif //GAMEOFLIFE_UTILITY_H
