#ifndef GAMEOFLIFE_OPTIONS_H
#define GAMEOFLIFE_OPTIONS_H

#include <vector>
#include <string>
#include <optional>

class Options {
public:
    bool ShowGridCheckbox();

    bool ShowContinuousSimulationCheckbox();

    /// @brief Fetches only new log messages.
    std::vector<std::string> &GetLogMessages();

private:
    std::vector<std::string> log_messages_;
    bool show_grid_{false};
    bool continuous_simulation_{false};
};


#endif //GAMEOFLIFE_OPTIONS_H
