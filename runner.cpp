#include "simulator.h"

#include "ThirdParty/imgui/imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

void WaitForEvent(sf::RenderWindow &window);

int main() {
    sf::RenderWindow window({Config::Screen::WIDTH, Config::Screen::HEIGHT}, "Cellular Automata");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    /// Setup
    std::unique_ptr<Simulator> simulator{std::make_unique<Simulator>(window)};
    simulator->Setup();

    sf::Clock deltaClock;
    while (window.isOpen() && !Config::MenuBar::QUIT) {
        window.clear();
        WaitForEvent(window);
        ImGui::SFML::Update(window, deltaClock.restart());

        simulator->Run();

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}

void WaitForEvent(sf::RenderWindow &window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
