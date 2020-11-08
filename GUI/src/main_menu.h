#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include "Simulator/src/data.h"
#include <memory>
#include <optional>

/// @brief Contains all the main menu GUI components and logic.
class MainMenu {
public:
    /// @brief Initializes the rules list which is shown and can be selected from the combo-box.
    /// Also, takes the first rule from the list and initializes it as the selected rule.
    /// @param rules All possible rules used in the simulation
    void InitializeRulesList(Rules &&rules);

    /// @brief Displays the main menu GUI window on the screen.
    SimulatorState Show();

    /// @brief Fetches only new log messages.
    std::optional<std::vector<std::string>> GetLogMessages();

    /// @section Getters

    std::shared_ptr<std::vector<bool>> GetInitialCellsGeneration() const;

    Rule *GetSelectedRule();

    int GetRow() const;

    int GetColumn() const;

private:
    void SetInitialRule(Rule &selected_rule);

    void InitialCellsStateWindow();

    void ShowRuleWindow();

    void ShowSimulationWindow();

    void ShowSimulationButtons();

    void PlayButton();

    void PauseButton();

    void StopButton();

    void UserDefinedButton();

    void RandomButton();

    void PopulateRandomizedInitialCellState() const;

    void ResetButton();

    void ApplyButton();

    void ShowGridSizeWindowSection();

    void ShowFillCellStateWindow();

    Rules rules_;
    Rule *selected_rule_{nullptr};
    std::shared_ptr<std::vector<bool>> initial_cell_generation_{nullptr};
    SimulatorState simulator_state_;
    std::vector<std::string> log_messages_;
    int row_{1};
    int column_{8};
    int row_temp_{1};
    int column_temp_{8};
};

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
