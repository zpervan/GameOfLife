#ifndef GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
#define GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_

#include "GUI/src/config.h"
#include "GUI/src/assets.h"
#include "Simulator/src/data.h"
#include "ThirdParty/imgui/imgui.h"
#include "ThirdParty/imgui/imgui-SFML.h"

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
		static std::size_t current_rule_index{0};
		const auto &current_rule_label = Data::rules.at(current_rule_index).first;

		if (ImGui::BeginCombo("", current_rule_label.c_str()))
		{
		  for (std::size_t i{0}; i < Data::rules.size(); i++)
		  {
			const bool is_selected{current_rule_index == i};

			if (ImGui::Selectable(Data::rules.at(i).first.c_str(), is_selected))
			{
			  current_rule_index = i;
			  Data::current_rule = Data::rules.at(i);
			}

			if (is_selected)
			{
			  ImGui::SetItemDefaultFocus();
			}
		  }
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
		if (i == 0) ImGui::ImageButton(*Assets::GetPlayButton(), 1);
		if (i == 1) ImGui::ImageButton(*Assets::GetPauseButton(), 1);
		if (i == 2) ImGui::ImageButton(*Assets::GetStopButton(), 1);
		ImGui::PopID();
		ImGui::SameLine();
	  }
	}
}

#endif //GAMEOFLIFE_MAIN_COMPONENTS_SIMULATOR_MAIN_MENU_H_
