#ifndef GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
#define GAMEOFLIFE_MAIN_COMMON_CONFIG_H_

#include "ThirdParty/imgui/imgui.h"

namespace Config {
    namespace Screen {
        constexpr unsigned int WIDTH{1024};
        constexpr unsigned int HEIGHT{768};
    }

    namespace Flag {
        constexpr float NO_SPACING{0.0};
    }

    namespace MenuBar {
        constexpr float VERTICAL_SIZE{19.0};
        static bool SHOW_ABOUT{false};
        static bool SHOW_USAGE{false};
        static bool QUIT{false};
    }

    namespace MainMenu {
        constexpr float WIDTH{Screen::WIDTH * 0.25};
        constexpr float HEIGHT{(Screen::HEIGHT * 0.75) - MenuBar::VERTICAL_SIZE};

        const ImVec2 ORIGIN{0.0, MenuBar::VERTICAL_SIZE};
        const ImVec2 SIZE{WIDTH, HEIGHT};
        const ImVec2 BUTTON_SIZE{WIDTH / 2.5, MenuBar::VERTICAL_SIZE};
    }

    namespace SimulatorLog {
        constexpr float WIDTH{Screen::WIDTH * 0.25};
        constexpr float HEIGHT{Screen::HEIGHT * 0.25};

        const ImVec2 ORIGIN{0.0, MainMenu::HEIGHT + MenuBar::VERTICAL_SIZE};
    }

    namespace RulePreview {
        constexpr float WIDTH{Screen::WIDTH - MainMenu::WIDTH};
        constexpr float HEIGHT{(Screen::HEIGHT - MenuBar::VERTICAL_SIZE) * 0.4};
        constexpr float CELL_GROUP_OFFSET{190.0};
        constexpr float NEW_STATE_CELL_OFFSET{80};

        const ImVec2 ORIGIN{MainMenu::WIDTH, MenuBar::VERTICAL_SIZE};
        const ImVec2 SIZE{WIDTH, HEIGHT};
    }

    namespace InitialCellsState {
        constexpr float WIDTH{Screen::WIDTH - MainMenu::WIDTH};
        constexpr float HEIGHT{Screen::HEIGHT * 0.1};
        constexpr float HORIZONTAL_OFFSET{Config::InitialCellsState::WIDTH * 0.3};

        const ImVec2 ORIGIN{MainMenu::WIDTH, RulePreview::HEIGHT + MenuBar::VERTICAL_SIZE};
        const ImVec2 SIZE{WIDTH, HEIGHT};
    }

    namespace Cell {
        const ImVec2 SIZE{40.0, 40.0};
    }

    namespace Viewport {
        const sf::Vector2f SCREEN_SIZE{Config::Screen::WIDTH - Config::MainMenu::WIDTH,
                                       Config::Screen::HEIGHT - MenuBar::VERTICAL_SIZE};
    }
}

#endif //GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
