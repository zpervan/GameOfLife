#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include "Simulator/src/data.h"

class MainMenu {
public:
    MainMenu(const Rules &rules, Rule &current_rule, std::bitset<8> &initial_cell_state);

    void Show();

private:
    void ShowInitialCellsStateWindow();

    void ShowRuleWindow();

    void ShowSimulationWindow();

    void ShowSimulationButtons();

    void PlayButton() const;

    void PauseButton() const;

    void StopButton() const;

    const Rules &rules_;
    Rule &current_rule_;
    std::bitset<8> &initial_cells_state_;
};

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
