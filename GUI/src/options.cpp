#include "GUI/src/options.h"

#include "ThirdParty/imgui/imgui.h"
#include "ThirdParty/fmt/include/fmt/core.h"

bool Options::ShowGridCheckbox() {
    if (ImGui::Checkbox("Show Grid?", &show_grid_)) {
        std::string grid_state{"Grid on"};
        if (!show_grid_) {
            grid_state = "Grid off";
        }
        log_messages_.emplace_back(std::move(grid_state));
    }
    return show_grid_;
}

std::vector<std::string> &Options::GetLogMessages() {
    return log_messages_;
}
