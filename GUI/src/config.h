#ifndef GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
#define GAMEOFLIFE_MAIN_COMMON_CONFIG_H_

#include "ThirdParty/imgui/imgui.h"

namespace Config {
    namespace Screen {
        constexpr unsigned int WIDTH{1024};
        constexpr unsigned int HEIGHT{768};
    }

    namespace MainMenu {
        constexpr float VERTICAL_OFFSET{20.0};
        constexpr float WIDTH{Screen::WIDTH * 0.25};
        constexpr float HEIGHT{Screen::HEIGHT - VERTICAL_OFFSET};

        const ImVec2 ORIGIN{0.0, VERTICAL_OFFSET};
        const ImVec2 SIZE{WIDTH, HEIGHT};
        const ImVec2 BUTTON_SIZE{WIDTH / 2.5, VERTICAL_OFFSET};
    }

    namespace MenuBar {
        static bool SHOW_ABOUT{false};
        static bool SHOW_USAGE{false};
        static bool QUIT{false};
    }

    namespace RulePreview {
        constexpr float VERTICAL_OFFSET{20.0};
        constexpr float WIDTH{Screen::WIDTH - MainMenu::WIDTH};
        constexpr float HEIGHT{(Screen::HEIGHT - VERTICAL_OFFSET) * 0.4};
        constexpr float CELL_GROUP_OFFSET{190.0};
        constexpr float NEW_STATE_CELL_OFFSET{80};

        const ImVec2 ORIGIN{MainMenu::WIDTH, VERTICAL_OFFSET};
        const ImVec2 SIZE{WIDTH, HEIGHT};

        static bool SHOW{true};
    }

    namespace InitialCellsState {
        constexpr float WIDTH{Screen::WIDTH - MainMenu::WIDTH};
        constexpr float HEIGHT{Screen::HEIGHT * 0.1};
        constexpr float HORIZONTAL_OFFSET{Config::InitialCellsState::WIDTH * 0.3};
        constexpr float VERTICAL_OFFSET{20.0};

        const ImVec2 ORIGIN{MainMenu::WIDTH, RulePreview::HEIGHT + VERTICAL_OFFSET};
        const ImVec2 SIZE{WIDTH, HEIGHT};

        static bool SHOW{true};
    }

    namespace Flag {
        constexpr float NO_SPACING{0.0};
    }

    namespace Cell {
        const ImVec2 SIZE{40.0, 40.0};
    }
}

#endif //GAMEOFLIFE_MAIN_COMMON_CONFIG_H_
