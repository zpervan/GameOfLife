#ifndef GAMEOFLIFE_UTILITY_H
#define GAMEOFLIFE_UTILITY_H

#include "ThirdParty/imgui/imgui.h"
#include <cstdlib>

namespace Utility {
    static inline void AddVerticalSpacing(std::size_t count) {
        for (std::size_t i{0}; i < count; i++)
            ImGui::NewLine();
    }
}

#endif //GAMEOFLIFE_UTILITY_H
