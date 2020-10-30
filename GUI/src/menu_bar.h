#ifndef GAMEOFLIFE_GUI_SRC_MENU_BAR_H_
#define GAMEOFLIFE_GUI_SRC_MENU_BAR_H_

#include "GUI/src/config.h"
#include "ThirdParty/imgui/imgui.h"
#include <iostream>

namespace AboutWindow {
    static void Show(bool *open);
}

namespace UsageWindow {
    static void Show(bool *open);
}

namespace MenuBar {
    void Show() {
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Application")) {
                ImGui::MenuItem("Restart", nullptr);
                ImGui::MenuItem("Quit", "Alt+F4", &Config::MenuBar::QUIT);
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Help")) {
                ImGui::MenuItem("Usage", nullptr, &Config::MenuBar::SHOW_USAGE);
                ImGui::MenuItem("About", nullptr, &Config::MenuBar::SHOW_ABOUT);

                if (ImGui::BeginMenu("Wikipedia links")) {
                    /// @todo: Add logic to open link in web-browser
                    ImGui::MenuItem("Cellular automata:  https://en.wikipedia.org/wiki/Cellular_automaton");
                    ImGui::EndMenu();
                }

                ImGui::EndMenu();
            }

            if (Config::MenuBar::SHOW_USAGE) { UsageWindow::Show(&Config::MenuBar::SHOW_USAGE); }
            if (Config::MenuBar::SHOW_ABOUT) { AboutWindow::Show(&Config::MenuBar::SHOW_ABOUT); }

            ImGui::EndMainMenuBar();
        }
    }

}

void AboutWindow::Show(bool *open) {
    if (!ImGui::Begin("About", open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Created by Zvonimir Pervan");
    ImGui::End();
}

void UsageWindow::Show(bool *open) {
    if (!ImGui::Begin("Usage", open)) {
        ImGui::End();
        return;
    }

    ImGui::Text("Insert usage text");
    ImGui::End();
}

#endif //GAMEOFLIFE_GUI_SRC_MENU_BAR_H_
