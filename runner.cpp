#include "Simulator/src/rules.h"
#include "GUI/src/main_menu.h"
#include "GUI/src/assets.h"
#include "GUI/src/menu_bar.h"
#include "GUI/src/rule_preview.h"
#include "GUI/src/initial_cell_state.h"

#include "ThirdParty/imgui/imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
  sf::RenderWindow window({Config::Screen::WIDTH, Config::Screen::HEIGHT}, "Cellular Automata");
  window.setVerticalSyncEnabled(true);
  ImGui::SFML::Init(window);

  /// Setup
  Data::rules = Rules::CreateBasicRules();
  Data::current_rule = Data::rules.front();
  Assets::Initialize();
  RulePreview rule_preview{Data::current_rule};
  InitialCellState initial_cell_state{std::bitset<8>(1)};

  sf::Clock deltaClock;
  while (window.isOpen() && !Config::MenuBar::QUIT)
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

	if (Config::RulePreview::SHOW)      rule_preview.Show();
	if (Config::InitialCellState::SHOW) initial_cell_state.Show();

	window.clear();
	ImGui::SFML::Render(window);
	window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}