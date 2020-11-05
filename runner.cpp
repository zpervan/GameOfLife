#include "Simulator/src/rules_creator.h"
#include "Simulator/src/cellular_automata_algorithm.h"
#include "GUI/src/main_menu.h"
#include "GUI/src/assets.h"
#include "GUI/src/menu_bar.h"
#include "GUI/src/rule_preview.h"
#include "GUI/src/initial_cells_state.h"
#include "GUI/src/viewport.h"

#include "ThirdParty/imgui/imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main() {
    sf::RenderWindow window({Config::Screen::WIDTH, Config::Screen::HEIGHT}, "Cellular Automata");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    /// Setup
    Data::rules = RulesCreator::CreateBasicRules();
    Data::selected_rule = Data::rules.front();
    SimulatorState simulator_state;

    Assets::Initialize();
    MainMenu main_menu{Data::rules, Data::selected_rule, Data::initial_cell_state, simulator_state};
    RulePreview rule_preview{Data::selected_rule};
    InitialCellsState initial_cell_state{Data::initial_cell_state};
    CellularAutomataAlgorithm algorithm;
    Viewport viewport{window};
    sf::Clock deltaClock;

    while (window.isOpen() && !Config::MenuBar::QUIT) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        MenuBar::Show();
        main_menu.Show();

        if (!simulator_state.run && !simulator_state.pause) {
            rule_preview.Show();
            initial_cell_state.Show();

            const std::vector<bool> initial_cell_statez
                    {Data::initial_cell_state[0], Data::initial_cell_state[1], Data::initial_cell_state[2],
                     Data::initial_cell_state[3], Data::initial_cell_state[4], Data::initial_cell_state[5],
                     Data::initial_cell_state[6], Data::initial_cell_state[7]};
            algorithm.SetRule(Data::selected_rule.second);

            algorithm.SetInitialCellState(initial_cell_statez);
            window.clear();
        }

        if (simulator_state.run && !simulator_state.stop) {
            if (Cell::column_ == 8) {
                Cell::row_++;
                Cell::column_ = 0;
            }

            viewport.SetCellState(*algorithm.CreateNewCellState(Cell::column_), Cell::row_, Cell::column_);
            viewport.Show();
            Cell::column_++;
            std::cout << "Hey, the simulator is running" << std::endl;
            if (simulator_state.pause) std::cout << "Hey, the simulator is paused" << std::endl;
        }

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}