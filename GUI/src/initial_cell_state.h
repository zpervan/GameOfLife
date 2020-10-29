#ifndef GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
#define GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_

#include <bitset>

class InitialCellState
{
  public:
	explicit InitialCellState(const std::bitset<8> &initial_cell_state);

	/// @brief Displays the rule preview window
	void Show();

  private:
	const std::bitset<8> &initial_cell_state_;
};

#endif //GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
