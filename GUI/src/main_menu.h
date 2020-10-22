#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "GUI/src/config.h"
#include "ThirdParty/imgui/imgui.h"
#include "ThirdParty/imgui/imgui-SFML.h"
#include "ThirdParty/fmt/include/fmt/core.h"

namespace MainMenu
{
	void SimulationButtons();

	void Show()
	{
	  ImGui::SetNextWindowPos(Config::MainMenu::ORIGIN);
	  ImGui::SetNextWindowSize(Config::MainMenu::SIZE);
	  ImGui::Begin("Simulator menu");
	  if (ImGui::CollapsingHeader("Initial cell state"))
	  {
		ImGui::Button("Random", Config::MainMenu::BUTTON_SIZE);
		ImGui::SameLine();
		ImGui::Button("User Defined", Config::MainMenu::BUTTON_SIZE);
		/// @todo: Add selectables to define a begin state
	  }

	  if (ImGui::CollapsingHeader("Rule"))
	  {
		const char *rules[]{"Create me", "2", "3"};
		if (ImGui::BeginCombo("", rules[0]))
		{
		  /// @todo: Fill with rules
		  ImGui::EndCombo();
		}
		ImGui::NewLine();
		ImGui::Button("Apply", Config::MainMenu::BUTTON_SIZE);
		ImGui::SameLine();
		ImGui::Button("Reset", Config::MainMenu::BUTTON_SIZE);
	  }

	  if (ImGui::CollapsingHeader("Simulation"))
	  {

		SimulationButtons();
		///todo: Make simulation speed global
		int simulation_speed{0};
		ImGui::NewLine();
		ImGui::Text("Simulation speed");
		ImGui::SliderInt("", &simulation_speed, -2, 2);
	  }

	  ImGui::End();
	}

	void SimulationButtons()
	{
	  const std::array<std::string, 3> button_names{"STOP", "PAUSE", "START"};
	  for (std::size_t i{0}; i < button_names.size(); i++)
	  {
		ImGui::PushID(i);
		ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.7f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.8f, 0.8f));
		ImGui::Button(button_names.at(i).c_str());
		ImGui::PopStyleColor(3);
		ImGui::PopID();
		ImGui::SameLine();
	  }
	}
}

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
