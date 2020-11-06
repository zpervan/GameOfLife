#include "GUI/src/main_menu.h"

#include "GUI/src/config.h"
#include "GUI/src/assets.h"
#include "GUI/src/utility.h"
#include "ThirdParty/imgui/imgui-SFML.h"
#include <memory>
#include <utility>

void MainMenu::InitializeRulesList(Rules &&rules) {
    rules_ = std::move(rules);
    SetInitialRule(rules_.front());
}

void MainMenu::SetInitialRule(Rule &selected_rule) {
    selected_rule_ = &selected_rule;
}

std::shared_ptr<std::vector<bool>> MainMenu::GetInitialCellsState() const {
    return initial_cell_states_;
}

int MainMenu::GetRow() const {
    return row_;
}

int MainMenu::GetColumn() const {
    return column_;
}

Rule *MainMenu::GetSelectedRule() {
    return selected_rule_;
}

SimulatorState MainMenu::Show() {
    simulator_state_ = SimulatorState::NO_CHANGE;
    ImGui::SetNextWindowPos(Config::MainMenu::ORIGIN);
    ImGui::SetNextWindowSize(Config::MainMenu::SIZE);
    ImGui::Begin("Simulator menu");

    RuleWindow();
    InitialCellsStateWindow();
    SimulationWindow();

    ImGui::End();
    return simulator_state_;
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
                *selected_rule_ = rules_.at(i);
            }

            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    Utility::AddVerticalSpacing(1);
}

void MainMenu::InitialCellsStateWindow() {
    ImGui::CollapsingHeader("Initial cells state");

    ImGui::Text("Grid size");
    ImGui::SameLine();
    Utility::HelpMarker(
            "To display the initial cell state preview, firstly set the row and column size of the grid. "
            "The minimal value of a row is 1 and of a column is 3. Maximum value of row and column is 300.");

    ImGui::InputInt("Row", &row_);
    ImGui::InputInt("Column", &column_);

    ResetButton();
    ImGui::SameLine();
    ApplyButton();

    ImGui::NewLine();

    ImGui::Text("Fill cells");
    /// @todo: Add selectables or some input field to define a begin state
    ImGui::Button("User Defined", Config::MainMenu::BUTTON_SIZE);
    ImGui::SameLine();
    RandomButton();
}

void MainMenu::ApplyButton() {
    static std::string grid_size_warning{"Enter grid size values"};
    if (ImGui::Button("Apply", Config::MainMenu::BUTTON_SIZE)) {
        if ((row_ < 0) || (column_ < 0)) {
            grid_size_warning = "Grid size can not be a negative number";
        } else if ((row_ == 0) || ((column_ < 3) && (column_ >= 0))) {
            grid_size_warning = "Values are below minimal values!";
        } else if ((row_ > 300) || (column_ > 300)) {
            grid_size_warning = "Grid size is larger than 300";
        } else {
            grid_size_warning = "Grid size is successfully set";
        }
    }

    ImGui::Text("%s", grid_size_warning.c_str());
}

void MainMenu::ResetButton() {
    if (ImGui::Button("Reset", Config::MainMenu::BUTTON_SIZE)) {
        row_ = 0;
        column_ = 0;
    }
}

void MainMenu::RandomButton() {
    static std::string random_button_message{"Set initial cells state"};
    if (ImGui::Button("Random", Config::MainMenu::BUTTON_SIZE)) {
        if (!initial_cell_states_) {
            initial_cell_states_ = std::make_shared<std::vector<bool>>();
        }

        if ((row_ == 0) && (column_ == 0)) {
            random_button_message = "Grid size is not set";
        } else {
            PopulateRandomizedInitialCellState();
            random_button_message = "Randomized!";
        }
    }
    ImGui::Text("%s", random_button_message.c_str());
}

void MainMenu::PopulateRandomizedInitialCellState() const {
    std::bitset<300> initial_cell_state{Utility::GenerateRandomNumberInRange(0, column_)};

    if (!initial_cell_states_->empty()) {
        initial_cell_states_->clear();
    } else {
        initial_cell_states_->reserve(column_);
    }

    for (std::size_t i{0}; i < column_; i++) {
        initial_cell_states_->emplace_back(initial_cell_state[i]);
    }
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
        simulator_state_ = SimulatorState::RUN;
    }
    ImGui::PopID();
    ImGui::SameLine();
}

void MainMenu::PauseButton() {
    ImGui::PushID(1);
    if (ImGui::ImageButton(*Assets::GetPauseButton(), 1)) {
        simulator_state_ = SimulatorState::PAUSE;
    }
    ImGui::PopID();
    ImGui::SameLine();
}

void MainMenu::StopButton() {
    ImGui::PushID(2);
    if (ImGui::ImageButton(*Assets::GetStopButton(), 1)) {
        simulator_state_ = SimulatorState::STOP;
    }
    ImGui::PopID();
    ImGui::SameLine();
}
