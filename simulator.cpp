#include "simulator.h"

#include "GUI/src/assets.h"
#include "GUI/src/menu_bar.h"
#include "Simulator/src/rules_creator.h"

void Simulator::Setup() {
    main_menu_.InitializeRulesList(RulesCreator::CreateListOfRules());
}

void Simulator::Run() {
    MenuBar::Show();

    if (auto main_menu_state = main_menu_.Show(); main_menu_state != SimulatorState::NO_CHANGE) {
        simulator_state_ = main_menu_state;
    }

    if (simulator_state_ == SimulatorState::INITIALIZATION) {
        Initialize();
    }

    if (simulator_state_ == SimulatorState::RUN) {
        Simulate();
    }

    if (simulator_state_ == SimulatorState::PAUSE) {
        Pause();
    }

    if (simulator_state_ == SimulatorState::STOP) {
        Reset();
        Setup();
    }

    ShowSimulatorLog();
}

void Simulator::Initialize() {
    Cell::row_ = 0;
    Cell::column_ = 0;
    rule_preview_.SetRule(*main_menu_.GetSelectedRule());
    rule_preview_.Show();
    initial_cell_generation_state_window_.Show();

    if (initial_cell_generation_ = main_menu_.GetInitialCellsGeneration(); initial_cell_generation_) {
        initial_cell_generation_state_window_.UpdateInitialCellGenerationState(*initial_cell_generation_);
        algorithm_.SetRule(main_menu_.GetSelectedRule()->second);
        algorithm_.SetInitialCellGenerationState(*initial_cell_generation_);
        viewport_.SetGridSize(main_menu_.GetRow(), main_menu_.GetColumn());
    }
}

void Simulator::Simulate() {
    if (!IsSimulationInitialized()) {
        return;
    }

    viewport_.ShowGrid(main_menu_.GetShowGrid());
    viewport_.SetCellState(*algorithm_.CreateNewCellState(Cell::column_), Cell::row_, Cell::column_);
    viewport_.Show();

    Cell::column_++;
    if (Cell::column_ == main_menu_.GetColumn()) {
        Cell::row_++;
        Cell::column_ = 0;
    }

    if (Cell::row_ == main_menu_.GetRow()) {
        simulator_state_ = SimulatorState::PAUSE;
        SetLogMessage("[Simulation] End");
    }
}

void Simulator::SetLogMessage(std::string message) {
    simulator_log_.SetMessages({std::move(message)});
}

void Simulator::Pause() {
    if (!IsSimulationInitialized()) {
        return;
    }

    viewport_.Show();
}

void Simulator::Reset() {
    simulator_state_ = SimulatorState::INITIALIZATION;
    main_menu_ = MainMenu();
    rule_preview_ = RulePreview();
    initial_cell_generation_state_window_ = InitialCellGenerationStateWindow();
    algorithm_ = CellularAutomataAlgorithm();
}

void Simulator::ShowSimulatorLog() {
    if (main_menu_.GetLogMessages().has_value()) {
        simulator_log_.SetMessages(*main_menu_.GetLogMessages());
    }
    simulator_log_.Show();
}

Simulator::Simulator(sf::RenderWindow &window) :
        simulator_state_(SimulatorState::INITIALIZATION),
        main_menu_(MainMenu()),
        rule_preview_(RulePreview()),
        initial_cell_generation_state_window_(InitialCellGenerationStateWindow()),
        algorithm_(CellularAutomataAlgorithm()),
        viewport_(window) {
    Assets::Initialize();
}

bool Simulator::IsSimulationInitialized() {
    if (!initial_cell_generation_) {
        simulator_state_ = SimulatorState::INITIALIZATION;
        SetLogMessage("[Simulation] Not initialized");
    }
    return static_cast<bool>(initial_cell_generation_);
}
