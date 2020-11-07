#include "GUI/src/simulator_log.h"

#include "GUI/src/config.h"
#include "ThirdParty/imgui/imgui.h"
#include <algorithm>

void SimulatorLog::Show() {
    ImGui::SetNextWindowPos(Config::SimulatorLog::ORIGIN);
    ImGui::SetNextWindowSize({Config::SimulatorLog::WIDTH, Config::SimulatorLog::HEIGHT});
    ImGui::Begin("Simulator log");

    DisplayLogMessages();

    ImGui::End();
}

void SimulatorLog::DisplayLogMessages() {
    std::for_each(messages_.rbegin(), messages_.rend(),
                  [](const std::string &message) { ImGui::Text("%s", message.c_str()); });
}

void SimulatorLog::SetMessages(std::vector<std::string> messages) {
    if (!messages.empty()) {
        std::move(messages.begin(), messages.end(), std::back_inserter(messages_));
    }
}
