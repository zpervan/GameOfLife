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
        viewport_.Show();
    }

    if (simulator_state_ == SimulatorState::STOP) {
        Reset();
        Setup();
    }
}

void Simulator::Initialize() {
    Cell::row_ = 0;
    Cell::column_ = 0;
    rule_preview_.SetRule(*main_menu_.GetSelectedRule());
    rule_preview_.Show();
    initial_cell_state_window_.Show();

    if (initial_cell_states_ = main_menu_.GetInitialCellsState(); initial_cell_states_) {
        initial_cell_state_window_.UpdateInitialCellStates(*initial_cell_states_);
        algorithm_.SetRule(main_menu_.GetSelectedRule()->second);
        algorithm_.SetInitialCellState(*initial_cell_states_);
        viewport_.SetGridSize(main_menu_.GetRow(), main_menu_.GetColumn());
    }
}

void Simulator::Simulate() {
    viewport_.SetCellState(*algorithm_.CreateNewCellState(Cell::column_), Cell::row_, Cell::column_);
    viewport_.Show();

    Cell::column_++;
    if (Cell::column_ == main_menu_.GetColumn()) {
        Cell::row_++;
        Cell::column_ = 0;
    }

    if (Cell::row_ == main_menu_.GetRow()) {
        simulator_state_ = SimulatorState::PAUSE;
    }
}

void Simulator::Reset() {
    simulator_state_ = SimulatorState::INITIALIZATION;
    main_menu_ = MainMenu();
    rule_preview_ = RulePreview();
    initial_cell_state_window_ = InitialCellsStateWindow();
    algorithm_ = CellularAutomataAlgorithm();
}

Simulator::Simulator(sf::RenderWindow &window) :
        simulator_state_(SimulatorState::INITIALIZATION),
        main_menu_(MainMenu()),
        rule_preview_(RulePreview()),
        initial_cell_state_window_(InitialCellsStateWindow()),
        algorithm_(CellularAutomataAlgorithm()),
        viewport_(window) {
    Assets::Initialize();
}
