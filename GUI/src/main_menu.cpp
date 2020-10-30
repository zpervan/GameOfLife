#include "GUI/src/main_menu.h"

#include "GUI/src/config.h"
#include "GUI/src/assets.h"
#include "GUI/src/utility.h"
#include "ThirdParty/imgui/imgui-SFML.h"
#include <utility>

MainMenu::MainMenu(const Rules &rules, Rule &current_rule) : rules_(rules), current_rule_(current_rule) {}

void MainMenu::Show() {
    ImGui::SetNextWindowPos(Config::MainMenu::ORIGIN);
    ImGui::SetNextWindowSize(Config::MainMenu::SIZE);
    ImGui::Begin("Simulator menu");

    ShowRuleWindow();
    ShowInitialCellsStateWindow();
    ShowSimulationWindow();

    ImGui::End();
}

void MainMenu::ShowRuleWindow() {
    ImGui::CollapsingHeader("Rule selection");

    static std::size_t current_rule_index{0};
    const auto &current_rule_label = rules_.at(current_rule_index).first;

    if (ImGui::BeginCombo("", current_rule_label.c_str())) {
        for (std::size_t i{0}; i < rules_.size(); i++) {
            const bool is_selected{current_rule_index == i};

            if (ImGui::Selectable(rules_.at(i).first.c_str(), is_selected)) {
                current_rule_index = i;
                current_rule_ = rules_.at(i);
            }

            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    Utility::AddVerticalSpacing(1);
    ImGui::Button("Apply", Config::MainMenu::BUTTON_SIZE);
    ImGui::SameLine();
    ImGui::Button("Reset", Config::MainMenu::BUTTON_SIZE);
    Utility::AddVerticalSpacing(1);
}

void MainMenu::ShowInitialCellsStateWindow() {
    ImGui::CollapsingHeader("Initial cells state");
    ImGui::Button("Random", Config::MainMenu::BUTTON_SIZE);
    ImGui::SameLine();
    /// @todo: Add selectables or some input field to define a begin state
    ImGui::Button("User Defined", Config::MainMenu::BUTTON_SIZE);
}

void MainMenu::ShowSimulationWindow() {
    ImGui::CollapsingHeader("Simulation");
    ShowSimulationButtons();

    /// @todo: Make simulation speed global
    int simulation_speed{0};

    Utility::AddVerticalSpacing(1);
    ImGui::Text("Simulation speed");
    ImGui::SliderInt("", &simulation_speed, -2, 2);
    Utility::AddVerticalSpacing(1);
}

void MainMenu::ShowSimulationButtons() {
    const std::array<std::string, 3> button_names{"STOP", "PAUSE", "START"};
    for (std::size_t i{0}; i < button_names.size(); i++) {
        ImGui::PushID(i);
        if (i == 0) ImGui::ImageButton(*Assets::GetPlayButton(), 1);
        if (i == 1) ImGui::ImageButton(*Assets::GetPauseButton(), 1);
        if (i == 2) ImGui::ImageButton(*Assets::GetStopButton(), 1);
        ImGui::PopID();
        ImGui::SameLine();
    }
}
