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

SimulationMode Options::ShowSimulationModeCheckbox() {
    if (ImGui::Checkbox("Eternal simulation mode?", &simulation_mode_temp_)) {
        std::string continuous_simulation_message{"[Simulation mode] Finite"};

        if (simulation_mode_temp_) {
            continuous_simulation_message = "[Simulation mode] Eternal";
        }

        log_messages_.emplace_back(std::move(continuous_simulation_message));
    }
    return simulation_mode_temp_ ? SimulationMode::ETERNAL : SimulationMode::FINITE;
}

std::vector<std::string> &Options::GetLogMessages() {
    return log_messages_;
}
