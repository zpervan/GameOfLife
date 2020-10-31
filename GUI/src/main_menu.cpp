#include "GUI/src/main_menu.h"

#include "GUI/src/config.h"
#include "GUI/src/assets.h"
#include "GUI/src/utility.h"
#include "ThirdParty/imgui/imgui-SFML.h"
#include <utility>
#include <iostream>

MainMenu::MainMenu(const Rules &rules, Rule &current_rule, std::bitset<8> &initial_cell_state,
                   SimulatorState &simulator_state)
        : rules_{rules}, current_rule_{current_rule}, initial_cells_state_{initial_cell_state},
          simulator_state_{simulator_state} {}

void MainMenu::Show() {
    ImGui::SetNextWindowPos(Config::MainMenu::ORIGIN);
    ImGui::SetNextWindowSize(Config::MainMenu::SIZE);
    ImGui::Begin("Simulator menu");

    RuleWindow();
    InitialCellsStateWindow();
    SimulationWindow();

    ImGui::End();
}

void MainMenu::RuleWindow() {
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

void MainMenu::InitialCellsStateWindow() {
    ImGui::CollapsingHeader("Initial cells state");

    if (ImGui::Button("Random", Config::MainMenu::BUTTON_SIZE)) {
        initial_cells_state_ = std::bitset<8>(Utility::GenerateRandomNumberInRange(0, 255));
    }
    ImGui::SameLine();
    /// @todo: Add selectables or some input field to define a begin state
    ImGui::Button("User Defined", Config::MainMenu::BUTTON_SIZE);
}

void MainMenu::SimulationWindow() {
    ImGui::CollapsingHeader("Simulation");
    ShowSimulationButtons();

    /// @todo: Make simulation speed global because, this way, every iteration it will be initialized with a value of 0!
    int simulation_speed{0};

    Utility::AddVerticalSpacing(1);
    ImGui::Text("Simulation speed");
    ImGui::SliderInt("", &simulation_speed, -2, 2);
    Utility::AddVerticalSpacing(1);
}

void MainMenu::ShowSimulationButtons() {
    PlayButton();
    PauseButton();
    StopButton();
}

void MainMenu::PlayButton() {
    ImGui::PushID(0);
    if (ImGui::ImageButton(*Assets::GetPlayButton(), 1)) {
        std::cout << "Hello from cute play button!" << std::endl;
        simulator_state_.run = true;
        simulator_state_.pause = false;
        simulator_state_.stop = false;
    }
    ImGui::PopID();
    ImGui::SameLine();
}

void MainMenu::PauseButton() {
    ImGui::PushID(1);
    if (ImGui::ImageButton(*Assets::GetPauseButton(), 1)) {
        std::cout << "Hello from cute pouz button!" << std::endl;
        simulator_state_.pause = true;
    }
    ImGui::PopID();
    ImGui::SameLine();
}

void MainMenu::StopButton() {
    ImGui::PushID(2);
    if (ImGui::ImageButton(*Assets::GetStopButton(), 1)) {
        std::cout << "Hello from cute stahp button!" << std::endl;
        simulator_state_.run = false;
        simulator_state_.stop = true;
    }
    ImGui::PopID();
    ImGui::SameLine();
}
