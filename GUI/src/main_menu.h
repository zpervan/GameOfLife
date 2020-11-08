#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include "GUI/src/options.h"
#include "Simulator/src/data.h"
#include <memory>
#include <optional>

/// @brief Contains all the main menu GUI components and logic.
class MainMenu {
public:
    /// @brief Initializes the rules list which is shown in the combo-box and select a rule which will be applied
    /// throughout the simulation. Also, takes the first rule from the list and initializes it as the selected rule.
    /// @param rules All possible rules used in the simulation
    void InitializeRulesList(Rules &&rules);

    /// @brief Displays the main menu window.
    SimulatorState Show();

    /// Getters

    /// @brief Fetches only new log messages.
    std::optional<std::vector<std::string>> GetLogMessages();

    std::shared_ptr<std::vector<bool>> GetInitialCellsGeneration() const;

    Rule *GetSelectedRule();

    int GetRow() const;

    int GetColumn() const;

    bool GetShowGrid() const;

    bool GetContinuousSimulation() const;

private:
    void SetInitialRule(Rule &selected_rule);

    void ShowRuleWindow();

    void ShowGridAndCellParametersWindow();

    void ShowSimulationStateWindow();

    void ShowSimulationButtons();

    void ShowOptionsWindow();

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

    Options options_;
    Rules rules_;
    Rule *selected_rule_{nullptr};
    std::shared_ptr<std::vector<bool>> initial_cell_generation_{nullptr};
    SimulatorState simulator_state_;
    std::vector<std::string> log_messages_;
    int row_{1};
    int column_{8};
    int row_temp_{1};
    int column_temp_{8};
    bool show_grid_{false};
    bool continuous_simulation_{false};
};

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
