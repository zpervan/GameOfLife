#include "GUI/src/options.h"

#include "ThirdParty/imgui/imgui.h"
#include "ThirdParty/fmt/include/fmt/core.h"

bool Options::ShowGridCheckbox() {
    if (ImGui::Checkbox("Show grid?", &show_grid_)) {
        std::string grid_display_message{"[Grid] On"};
        if (!show_grid_) {
            grid_display_message = "[Grid] Off";
        }
        log_messages_.emplace_back(std::move(grid_display_message));
    }
    return show_grid_;
}

bool Options::ShowContinuousSimulationCheckbox() {
    if (ImGui::Checkbox("Continuous simulation?", &continuous_simulation_)) {
        std::string continuous_simulation_message{"[Simulation] Continuous"};
        if (!continuous_simulation_) {
            continuous_simulation_message = "[Simulation] Non-Continuous";
        }
        log_messages_.emplace_back(std::move(continuous_simulation_message));
    }
    return continuous_simulation_;
}

std::vector<std::string> &Options::GetLogMessages() {
    return log_messages_;
}
