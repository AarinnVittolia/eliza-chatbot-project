#include "ConversationManager.h"
#include "TextUtils.h"
#include <iostream>
#include <regex>

ConversationManager::ConversationManager()
    : finished_(false), fallbackIndex_(0) {
}

void ConversationManager::printWelcome() const {
    std::cout << "ELIZA: Hello, I am Eliza. Please have a seat and tell me what is on "
                 "your mind. Type \"bye\" whenever you would like to end our session.\n";
}

bool ConversationManager::isFinished() const {
    return finished_;
}

bool ConversationManager::isExitCommand(const std::string& normalizedInput) const {
    return std::regex_match(normalizedInput, std::regex(R"(bye\.?!?)", std::regex::icase));
}

std::string ConversationManager::repeatedResponseMessage() const {
    return "You have told me that before. Can you tell me something different?";
}

std::string ConversationManager::nextFallbackResponse() const {
    static const std::vector<std::string> fallbacks = {
        "Please tell me more about that.",
        "How does that make you feel?",
        "Why do you say that?",
        "Can you elaborate on that a little more?",
        "I see. What else is on your mind?"
    };
    const std::string& response = fallbacks[fallbackIndex_ % fallbacks.size()];
    fallbackIndex_++;
    return response;
}

std::string ConversationManager::dispatchToComponents(const std::string& input) const {
    std::string response;

    // Components are checked in a fixed order. The first component
    // whose patterns match the input "wins" and its response is used.
    response = genericVerb_.respond(input);
    if (!response.empty()) return response;

    response = relationship_.respond(input);
    if (!response.empty()) return response;

    response = concern_.respond(input);
    if (!response.empty()) return response;

    response = financial_.respond(input);
    if (!response.empty()) return response;

    response = wellbeing_.respond(input);
    if (!response.empty()) return response;

    response = education_.respond(input);
    if (!response.empty()) return response;

    response = entertainment_.respond(input);
    if (!response.empty()) return response;

    return "";
}

std::string ConversationManager::processInput(const std::string& rawInput) {
    std::string trimmed = TextUtils::trim(rawInput);
    std::string normalized = TextUtils::toLower(trimmed);

    // Check for the exit condition first.
    if (isExitCommand(normalized)) {
        finished_ = true;
        return "ELIZA: Goodbye. Take care of yourself, and thank you for talking with me.";
    }

    // An empty line does not count toward repeat detection; just
    // prompt the user to say something.
    if (trimmed.empty()) {
        return "ELIZA: I did not catch that. Could you say something?";
    }

    // Track how many times this exact (normalized) input has been
    // given before. If it has been seen already, nudge the user
    // toward a different response instead of answering normally.
    int& count = responseHistory_[normalized];
    count++;
    if (count > 1) {
        return "ELIZA: " + repeatedResponseMessage();
    }

    // Dispatch to the major functionality components in order.
    std::string response = dispatchToComponents(trimmed);
    if (!response.empty()) {
        return "ELIZA: " + response;
    }

    // Nothing matched; fall back to a generic, rotating response so
    // every input still receives an answer.
    return "ELIZA: " + nextFallbackResponse();
}
