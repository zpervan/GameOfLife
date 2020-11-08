#include "GUI/src/main_menu.h"

#include "GUI/src/config.h"
#include "GUI/src/assets.h"
#include "GUI/src/utility.h"
#include "ThirdParty/imgui/imgui-SFML.h"
#include <utility>

void MainMenu::InitializeRulesList(Rules &&rules) {
    rules_ = std::move(rules);
    SetInitialRule(rules_.front());
}

void MainMenu::SetInitialRule(Rule &selected_rule) {
    selected_rule_ = &selected_rule;
}

std::shared_ptr<std::vector<bool>> MainMenu::GetInitialCellsGeneration() const {
    return initial_cell_generation_;
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
    ImGui::SetNextWindowPos(Config::MainMenu::ORIGIN);
    ImGui::SetNextWindowSize(Config::MainMenu::SIZE);

    if (!log_messages_.empty()) log_messages_.clear();
    simulator_state_ = SimulatorState::NO_CHANGE;

    ImGui::Begin("Simulator menu");

    ShowRuleWindow();
    InitialCellsStateWindow();
    ShowSimulationWindow();

    ImGui::End();
    return simulator_state_;
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
                *selected_rule_ = rules_.at(i);
                log_messages_.emplace_back("New rule selected");
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
    ShowGridSizeWindowSection();
    ShowFillCellStateWindow();
}

void MainMenu::ApplyButton() {
    if (ImGui::Button("Apply", Config::MainMenu::BUTTON_SIZE)) {
        if ((row_temp_ < 0) || (column_temp_ < 0)) {
            log_messages_.emplace_back("Grid size can not be a negative number");
        } else if ((row_temp_ == 0) || ((column_temp_ < 3) && (column_temp_ >= 0))) {
            log_messages_.emplace_back("Values are below minimal values!");
        } else if ((row_temp_ > 300) || (column_temp_ > 300)) {
            log_messages_.emplace_back("Grid size is larger than 300");
        } else {
            row_ = row_temp_;
            column_ = column_temp_;
            log_messages_.emplace_back("Grid size successfully set");
        }
    }
}

void MainMenu::ResetButton() {
    if (ImGui::Button("Reset", Config::MainMenu::BUTTON_SIZE)) {
        row_ = 0;
        column_ = 0;
        row_temp_ = 0;
        column_temp_ = 0;
        log_messages_.emplace_back("Grid size reset");
    }
}

void MainMenu::RandomButton() {
    if (ImGui::Button("Random", Config::MainMenu::BUTTON_SIZE)) {
        if ((row_ == 0) && (column_ == 0)) {
            log_messages_.emplace_back("Grid size is not set");
        } else {
            if (!initial_cell_generation_) {
                initial_cell_generation_ = std::make_shared<std::vector<bool>>();
            }
            PopulateRandomizedInitialCellState();
            log_messages_.emplace_back("Randomized initial cell generation");
        }
    }
}

void MainMenu::PopulateRandomizedInitialCellState() const {
    std::bitset<300> initial_cell_state{Utility::GenerateRandomNumberInRange(0, column_)};

    if (!initial_cell_generation_->empty()) {
        initial_cell_generation_->clear();
    } else {
        initial_cell_generation_->reserve(column_);
    }

    for (std::size_t i{0}; i < column_; i++) {
        initial_cell_generation_->emplace_back(initial_cell_state[i]);
    }
}

void MainMenu::ShowSimulationWindow() {
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

void MainMenu::ShowGridSizeWindowSection() {
    ImGui::Text("Grid size");
    ImGui::SameLine();
    Utility::HelpMarker(
            "To display the initial cell state preview, firstly set the row and column size of the grid. "
            "The minimal value of a row is 1 and of a column is 3. Maximum value of row and column is 300.");

    ImGui::InputInt("Row", &row_temp_);
    ImGui::InputInt("Column", &column_temp_);

    ApplyButton();
    ImGui::SameLine();
    ResetButton();
    ImGui::NewLine();
}

void MainMenu::ShowFillCellStateWindow() {
    ImGui::Text("Fill cell states");
    ImGui::SameLine();
    Utility::HelpMarker(
            "Before each simulation start, we must define a initial cell generation. The states of the initial cell"
            " generation can be user defined or random.");
    /// @todo: Add selectables or some input field to define a begin state
    UserDefinedButton();
    ImGui::SameLine();
    RandomButton();
}

void MainMenu::UserDefinedButton() {
    if (ImGui::Button("User Defined", Config::MainMenu::BUTTON_SIZE)) {
        log_messages_.emplace_back("User defined logic not implemented");
    }
}

std::optional<std::vector<std::string>> MainMenu::GetLogMessages() {
    if (!log_messages_.empty()) {
        return log_messages_;
    }
    return std::nullopt;
}
