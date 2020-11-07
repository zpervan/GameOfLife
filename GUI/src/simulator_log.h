#ifndef GAMEOFLIFE_SIMULATOR_LOG_H
#define GAMEOFLIFE_SIMULATOR_LOG_H

#include <vector>
#include <string>

class SimulatorLog {
public:
    void SetMessages(std::vector<std::string> messages);

    void Show();

private:
    void DisplayLogMessages();

    std::vector<std::string> messages_;
};


#endif //GAMEOFLIFE_SIMULATOR_LOG_H
