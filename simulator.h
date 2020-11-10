#ifndef GAMEOFLIFE_SIMULATOR_H
#define GAMEOFLIFE_SIMULATOR_H

#include "GUI/src/main_menu.h"
#include "GUI/src/initial_cells_state.h"
#include "GUI/src/rule_preview.h"
#include "GUI/src/viewport.h"
#include "GUI/src/simulator_log.h"
#include "Simulator/src/cellular_automata_algorithm.h"
#include "Simulator/src/data.h"

/// @brief Represents the main simulator class which contains the whole GUI and Cellular Automata logic.
class Simulator {
public:
    /// @brief Contains the setup logic. Currently, initializes all possible rules that can be used in the simulation.
    void Setup();

    /// @brief Contains the logic for running the simulation -  GUI components, cellular automata algorithm output and
    /// the viewport (canvas) which displays the algorithm output.
    void Run();

    /// @brief Resets all the simulator values and states to it's initial values.
    void Reset();

    explicit Simulator(sf::RenderWindow &window);

    ~Simulator() = default;

private:
    void Initialize();

    void FiniteSimulation();

    void EternalSimulation();

    void Pause();

    void ShowSimulatorLog();

    bool IsSimulationInitialized();

    void SetLogMessage(std::string message);

    void ResetGridCount();

    void UpdateCellState();

    bool IsCellNotLastInRow() const;

    bool HasCellGenerationReachedTheEnd() const;

    std::shared_ptr<std::vector<bool>> initial_cell_generation_;
    SimulatorState simulator_state_;
    MainMenu main_menu_;
    RulePreview rule_preview_;
    InitialCellGenerationStateWindow initial_cell_generation_state_window_;
    CellularAutomataAlgorithm algorithm_;
    Viewport viewport_;
    SimulatorLog simulator_log_;
    SimulationMode simulation_mode_;
    std::size_t cell_row_index_{0};
    std::size_t cell_column_index_{0};
};


#endif //GAMEOFLIFE_SIMULATOR_H
