#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include "Simulator/src/data.h"

class MainMenu {
public:
    MainMenu(const Rules &rules, Rule &current_rule, std::bitset<8> &initial_cell_state);

    void Show();

private:
    void ShowSimulationButtons();

    void ShowInitialCellsStateWindow();

    void ShowRuleWindow();

    void ShowSimulationWindow();

    const Rules &rules_;
    Rule &current_rule_;
    std::bitset<8> &initial_cells_state_;
};

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
