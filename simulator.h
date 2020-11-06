#ifndef GAMEOFLIFE_SIMULATOR_H
#define GAMEOFLIFE_SIMULATOR_H

#include "GUI/src/main_menu.h"
#include "GUI/src/initial_cells_state.h"
#include "GUI/src/rule_preview.h"
#include "GUI/src/viewport.h"
#include "Simulator/src/cellular_automata_algorithm.h"
#include "Simulator/src/data.h"

class Simulator {
public:
    void Setup();

    void Run();

    void Reset();

    explicit Simulator(sf::RenderWindow &window);

    ~Simulator() = default;

private:
    std::shared_ptr<std::vector<bool>> initial_cell_states_;
    SimulatorState simulator_state_;
    MainMenu main_menu_;
    RulePreview rule_preview_;
    InitialCellsStateWindow initial_cell_state_window_;
    CellularAutomataAlgorithm algorithm_;
    Viewport viewport_;

    void Initialize();

    void Simulate();
};


#endif //GAMEOFLIFE_SIMULATOR_H
