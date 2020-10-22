#include "ThirdParty/imgui/imgui-SFML.h"
#include "GUI/src/config.h"
#include "GUI/src/main_menu.h"
#include "GUI/src/menu_bar.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
  sf::RenderWindow window({Config::Screen::WIDTH, Config::Screen::HEIGHT}, "");
  window.setVerticalSyncEnabled(true);
  ImGui::SFML::Init(window);

  window.setTitle("Cellular Automata");
  window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.

  sf::Clock deltaClock;
  while (window.isOpen() && !Config::GUI::QUIT)
  {
	sf::Event event{};
	while (window.pollEvent(event))
	{
	  ImGui::SFML::ProcessEvent(event);
	  if (event.type == sf::Event::Closed)
	  {
		window.close();
	  }
	}
	ImGui::SFML::Update(window, deltaClock.restart());

	MenuBar::Show();
	MainMenu::Show();

	window.clear(); // fill background with color
	ImGui::SFML::Render(window);
	window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}