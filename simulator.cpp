#include "simulator.h"

#include "GUI/src/assets.h"
#include "GUI/src/menu_bar.h"
#include "Simulator/src/rules_creator.h"


void Simulator::Setup() {
    main_menu_.InitializeRulesList(RulesCreator::CreateListOfRules());
    rule_preview_.SetRule(*main_menu_.GetSelectedRule());
}

void Simulator::Run() {
    MenuBar::Show();
    simulator_state_ = main_menu_.Show();

    if ((simulator_state_ == SimulatorState::INITIALIZATION) || (simulator_state_ == SimulatorState::STOP)) {
        Cell::row_ = 0;
        Cell::column_ = 0;
        rule_preview_.SetRule(*main_menu_.GetSelectedRule());
        rule_preview_.Show();
        initial_cell_state_.Show();

        if (Data::initial_cell_states = main_menu_.GetInitialCellsState(); Data::initial_cell_states) {
            initial_cell_state_.UpdateInitialCellStates(*Data::initial_cell_states);
            algorithm_.SetRule(Data::selected_rule.second);
            algorithm_.SetInitialCellState(*Data::initial_cell_states);
            viewport_.SetGridSize(main_menu_.GetRow(), main_menu_.GetColumn());
        }
    }

    if (simulator_state_ == SimulatorState::RUN) {
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

    if (simulator_state_ == SimulatorState::PAUSE) {
        viewport_.Show();
    }

}

void Simulator::Reset() {
}

Simulator::Simulator(sf::RenderWindow &window) :
        main_menu_(MainMenu()),
        rule_preview_(RulePreview()),
        initial_cell_state_(InitialCellsState()),
        algorithm_(CellularAutomataAlgorithm()),
        viewport_(window) {
    Assets::Initialize();
}
