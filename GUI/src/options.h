#ifndef GAMEOFLIFE_OPTIONS_H
#define GAMEOFLIFE_OPTIONS_H

#include "Simulator/src/data.h"
#include <vector>
#include <string>
#include <optional>

/// @brief Contains all the optional simulation logic.
class Options {
public:
    /// @brief Turns the grid ON or OFF based on the checkbox state.
    bool ShowGridCheckbox();

    /// @brief Changes the simulation mode from FINITE to ETERNAL and vice-versa.
    SimulationMode ShowSimulationModeCheckbox();

    /// @brief Fetches only new log messages.
    std::vector<std::string> &GetLogMessages();

private:
    std::vector<std::string> log_messages_;
    bool simulation_mode_temp_{false};
    bool show_grid_{false};
};


#endif //GAMEOFLIFE_OPTIONS_H
