#include <iostream>
#include <string>

#include "ConversationManager.h"

// Entry point for the ELIZA psychiatrist chatbot. This file only
// contains the top-level input/output loop; all of the actual
// conversation logic lives in ConversationManager and the major
// functionality components it owns.
int main() {
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
