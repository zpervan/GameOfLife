#ifndef GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
#define GAMEOFLIFE_MAIN_COMMON_CONFIG_H_

#include "ThirdParty/imgui/imgui.h"

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
		const ImVec2 BUTTON_SIZE{WIDTH / 2.5, 20.0};
	}

	namespace GUI
	{
		static bool SHOW_ABOUT{false};
		static bool SHOW_WIKI{false};
		static bool SHOW_USAGE{false};
		static bool QUIT{false};
	}
}

#endif //GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
