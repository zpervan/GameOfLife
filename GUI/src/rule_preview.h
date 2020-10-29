#ifndef GAMEOFLIFE_GUI_SRC_RULE_PREVIEW_H_
#define GAMEOFLIFE_GUI_SRC_RULE_PREVIEW_H_

#include <string>
#include <bitset>

class RulePreview
{
  public:
	explicit RulePreview(std::pair<std::string, std::bitset<8>> &current_rule);

	/// @brief Displays the rule preview window
	void Show();

  private:
	void CreateCurrentPatternCellGroup(std::size_t cell_group_index);
	void CreateNewStateCell(std::size_t cell_index);
	float CalculateCurrentPatternCellGroupStartXPosition(std::size_t cell_group_element_index);
	float CalculateNewStateCellXPosition(std::size_t cell_element_index);
	void CreateCurrentPatternCellGroupRow(std::size_t start_index, std::size_t end_index);
	void CreateNewStateCellRow(std::size_t start_index, std::size_t end_index);

	std::pair<std::string, std::bitset<8>> &current_rule_;
};

#endif //GAMEOFLIFE_GUI_SRC_RULE_PREVIEW_H_
