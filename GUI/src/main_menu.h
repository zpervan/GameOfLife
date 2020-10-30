#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include "Simulator/src/data.h"

class MainMenu {
public:
    MainMenu(const Rules &rules, Rule &current_rule);

    void Show();

private:
    void ShowSimulationButtons();

    void ShowInitialCellsStateWindow();

    void ShowRuleWindow();

    void ShowSimulationWindow();

    const Rules &rules_;
    Rule &current_rule_;
};

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
