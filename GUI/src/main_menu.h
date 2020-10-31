#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include "Simulator/src/data.h"

class MainMenu {
public:
    MainMenu(const Rules &rules, Rule &current_rule, std::bitset<8> &initial_cell_state,
             SimulatorState &simulator_state);

    void Show();

private:
    void InitialCellsStateWindow();

    void RuleWindow();

    void SimulationWindow();

    void ShowSimulationButtons();

    void PlayButton();

    void PauseButton();

    void StopButton();

    const Rules &rules_;
    Rule &current_rule_;
    std::bitset<8> &initial_cells_state_;
    SimulatorState &simulator_state_;

};

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
