#ifndef GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
#define GAMEOFLIFE_MAIN_COMMON_CONFIG_H_

#include "ThirdParty/imgui/imgui.h"
#include <SFML/Graphics.hpp>

namespace Config
{
	namespace Screen
	{
		constexpr unsigned int WIDTH{1024};
		constexpr unsigned int HEIGHT{768};
	}

	namespace MainMenu
	{
		constexpr float VERTICAL_OFFSET{20.0};
		constexpr float WIDTH{Screen::WIDTH * 0.25};
		constexpr float HEIGHT{Screen::HEIGHT - VERTICAL_OFFSET};

		const ImVec2 ORIGIN{0.0, VERTICAL_OFFSET};
		const ImVec2 SIZE{WIDTH, HEIGHT};
		const ImVec2 BUTTON_SIZE{WIDTH / 2.5, VERTICAL_OFFSET};
	}

	namespace MenuBar
	{
		static bool SHOW_ABOUT{false};
		static bool SHOW_USAGE{false};
		static bool QUIT{false};
	}

	namespace RulePreview
	{
		constexpr float VERTICAL_OFFSET{20.0};
		constexpr float WIDTH{Screen::WIDTH - MainMenu::WIDTH};
		constexpr float HEIGHT{(Screen::HEIGHT - VERTICAL_OFFSET) * 0.3};

		const ImVec2 ORIGIN{MainMenu::WIDTH, VERTICAL_OFFSET};
		const ImVec2 SIZE{WIDTH, HEIGHT};

		static bool SHOW{true};
	}
}

#endif //GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
