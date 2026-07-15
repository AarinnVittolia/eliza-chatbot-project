#ifndef CONVERSATION_MANAGER_H
#define CONVERSATION_MANAGER_H

#include <string>
#include <unordered_map>
#include <vector>

#include "GenericVerb.h"
#include "Relationship.h"
#include "Concern.h"
#include "Financial.h"
#include "Wellbeing.h"
#include "Education.h"
#include "Entertainment.h"

// Owns one instance of every major functionality component and
// controls the overall conversation: reading input, detecting the
// "bye" exit condition, catching repeated identical answers, and
// falling back to a generic response when no component's patterns
// match.
class ConversationManager {
public:
    ConversationManager();

    // Prints the opening welcome message.
    void printWelcome() const;

    // Processes one line of raw user input and returns ELIZA's
    // response. Sets the internal "finished" flag when the user
    // types "bye".
    std::string processInput(const std::string& rawInput);

    // True once the user has ended the conversation.
    bool isFinished() const;

private:
    bool finished_;

    // Tracks how many times each (lowercased, trimmed) user input has
    // been seen, so that repeated identical answers can be detected
    // and the user can be nudged toward a different response.
    std::unordered_map<std::string, int> responseHistory_;

    // Rotating index into the generic fallback responses, so repeated
    // unmatched input doesn't always get the exact same reply.
    mutable size_t fallbackIndex_;

    // One instance per major functionality component.
    GenericVerb genericVerb_;
    Relationship relationship_;
    Concern concern_;
    Financial financial_;
    Wellbeing wellbeing_;
    Education education_;
    Entertainment entertainment_;

    // Returns true if the trimmed, lowercased input is the exit
    // keyword "bye".
    bool isExitCommand(const std::string& normalizedInput) const;

    // Returns a message asking the user to say something different,
    // used when the exact same input has been seen before.
    std::string repeatedResponseMessage() const;

    // Returns the next generic fallback response for input that none
    // of the components recognized.
    std::string nextFallbackResponse() const;

    // Tries each component in turn and returns the first non-empty
    // response, or an empty string if none matched.
    std::string dispatchToComponents(const std::string& input) const;
};

#endif // CONVERSATION_MANAGER_H
