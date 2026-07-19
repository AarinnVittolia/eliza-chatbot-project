#include <iostream>
#include <string>

#include "Config.h"
#include "Region.h"
#include "Session.h"
#include "ConversationManager.h"

// Entry point for the ELIZA psychiatrist chatbot. Before the
// conversation loop starts, the program reads a configuration file,
// loads the initial session region layout and the registered session
// records, and displays/saves the initial region. This mirrors the
// Config/Region/Simulation-init/Region-output structure used in the
// QParking project. All of the actual conversation logic still lives
// in ConversationManager and the major functionality components it
// owns.
int main() {
    Config config;
    Region region;
    SessionList sessions;

    std::string configFile;
    std::cout << "Enter configuration filename: ";
    std::cin >> configFile;
    std::cin.ignore(); // discard the trailing newline before getline() calls

    // Read configuration file
    if (!config.readConfig(configFile)) {
        return 1;
    }

    std::cout << "\nConfiguration Loaded Successfully\n";
    std::cout << "Grid Rows      : " << config.rows << "\n";
    std::cout << "Grid Cols      : " << config.cols << "\n";
    std::cout << "Region File    : " << config.regionFile << "\n";
    std::cout << "Session File   : " << config.sessionFile << "\n";

    // Load initial session region
    if (!region.loadRegion(config.regionFile, config.rows, config.cols)) {
        return 1;
    }

    // Load registered session records
    if (!sessions.loadSessions(config.sessionFile)) {
        return 1;
    }

    // Display initial session region
    region.displayRegion();

    // Save initial region to output file
    region.saveRegion("initial_region_output.txt");
    std::cout << "\nInitial session region saved to initial_region_output.txt\n";

    std::cout << "\nSimulation initialized successfully.\n";

    // Hand off into the normal ELIZA conversation loop.
    ConversationManager manager;
    manager.printWelcome();

    std::string userInput;
    while (!manager.isFinished()) {
        std::cout << "You: ";
        if (!std::getline(std::cin, userInput)) {
            // No more input (e.g. end of file); end the session
            // gracefully instead of looping forever.
            break;
        }

        std::string response = manager.processInput(userInput);
        std::cout << response << "\n";
    }

    return 0;
}
