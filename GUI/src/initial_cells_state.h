#ifndef GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
#define GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_

#include <bitset>

class InitialCellsState {
public:
    explicit InitialCellsState(const std::bitset<8> &initial_cell_state);

    /// @brief Displays the "Initial cells state" window which contains cells initialized by the user or randomly.
    void Show();

private:
    void VisualizeInitialCellsState() const;

    [[nodiscard]] float CalculateCellXPosition(std::size_t i) const;

    const std::bitset<8> &initial_cell_state_;
};

#endif //GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
