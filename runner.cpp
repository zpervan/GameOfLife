#include "Simulator/src/rules_creator.h"
#include "GUI/src/main_menu.h"
#include "GUI/src/assets.h"
#include "GUI/src/menu_bar.h"
#include "GUI/src/rule_preview.h"
#include "GUI/src/initial_cells_state.h"

#include "ThirdParty/imgui/imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main() {
    sf::RenderWindow window({Config::Screen::WIDTH, Config::Screen::HEIGHT}, "Cellular Automata");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    /// Setup
    Data::rules = RuleCreator::CreateBasicRules();
    Data::current_rule = Data::rules.front();

    Assets::Initialize();
    MainMenu main_menu{Data::rules, Data::current_rule, Data::initial_cell_state};
    RulePreview rule_preview{Data::current_rule};
    InitialCellsState initial_cell_state{Data::initial_cell_state};

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

        if (Config::RulePreview::SHOW) rule_preview.Show();
        if (Config::InitialCellsState::SHOW) initial_cell_state.Show();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}