#ifndef GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
#define GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_

#include <vector>

/// @brief Represent the window section in which the initial cell generation preview is shown.
class InitialCellGenerationStateWindow {
public:
    /// @brief Initializes/updates the initial cell generation.
    /// @param initial_cell_generation_states Initial cell generation states
    void UpdateInitialCellGenerationState(const std::vector<bool> &initial_cell_generation_states);

    /// @brief Displays the initial cell generation window.
    void Show();

private:
    void VisualizeInitialCellsState() const;

    float CalculateCellXPosition(const size_t cell_index) const;

    std::vector<bool> initial_cell_generation_states_;
};

#endif //GAMEOFLIFE_GUI_SRC_INITIAL_CELL_STATE_H_
