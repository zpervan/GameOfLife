#ifndef GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
#define GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_

#include <bitset>
#include <vector>

class InitialCellsStateWindow {
public:
    void UpdateInitialCellStates(const std::vector<bool> &initial_cell_states);

    /// @brief Displays the "Initial cells state" window which contains cells initialized by the user or randomly.
    void Show();

private:
    void VisualizeInitialCellsState() const;

    [[nodiscard]] float CalculateCellXPosition(std::size_t i) const;

    std::vector<bool> initial_cell_states_{};
};

#endif //GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
