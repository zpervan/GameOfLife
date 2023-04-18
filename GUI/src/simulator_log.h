#ifndef GAMEOFLIFE_SIMULATOR_LOG_H
#define GAMEOFLIFE_SIMULATOR_LOG_H

#include <string>
#include <vector>

/// @brief Collects all log messages from the simulation and displays them in a log window.
class SimulatorLog
{
  public:
    /// @brief Set log messages which will be shown in the simulator log console.
    /// @param messages Log messages which will be displayed
    void SetMessages(std::vector<std::string> messages);

    /// @brief Displays the simulator log window.
    void Show();

  private:
    void DisplayLogMessages();

    std::vector<std::string> messages_;
};

#endif  // GAMEOFLIFE_SIMULATOR_LOG_H
