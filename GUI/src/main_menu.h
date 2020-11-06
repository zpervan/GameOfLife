#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include <memory>
#include "Simulator/src/data.h"

class MainMenu {
public:
    void InitializeRulesList(Rules &&rules);

    std::shared_ptr<std::vector<bool>> GetInitialCellsState() const;

    Rule *GetSelectedRule();

    int GetRow() const;

    int GetColumn() const;

    SimulatorState Show();

private:
    void SetInitialRule(Rule &selected_rule);

    void InitialCellsStateWindow();

    void RuleWindow();

    void SimulationWindow();

    void ShowSimulationButtons();

    void PlayButton();

    void PauseButton();

    void StopButton();

    void RandomButton();

    void PopulateRandomizedInitialCellState() const;

    void ResetButton();

    void ApplyButton();


    Rules rules_;
    Rule *selected_rule_{nullptr};
    std::shared_ptr<std::vector<bool>> initial_cell_states_{nullptr};
    SimulatorState simulator_state_;

    int row_{1};
    int column_{8};
};

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
