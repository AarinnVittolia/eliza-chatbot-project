#include "Wellbeing.h"
#include "TextUtils.h"
#include <regex>

std::string Wellbeing::respond(const std::string& input) const {
    std::smatch match;

    // Pattern 1: "I can't/cannot sleep"
    if (std::regex_search(input, match, std::regex(R"(i (?:can't|cannot) sleep)", std::regex::icase))) {
        return "What has been keeping you up at night?";
    }

    // Pattern 2: "I don't/do not exercise"
    if (std::regex_search(input, match, std::regex(R"(i (?:don't|do not) exercise)", std::regex::icase))) {
        return "What has kept you from exercising?";
    }

    // Pattern 3: "I started/start exercising"
    if (std::regex_search(input, match, std::regex(R"(i (?:started|start) exercising)", std::regex::icase))) {
        return "What made you decide to start exercising?";
    }

    // Pattern 4: "I take vitamins"
    if (std::regex_search(input, match, std::regex(R"(i take vitamins)", std::regex::icase))) {
        return "What made you start taking vitamins?";
    }

    // Pattern 5: "I need to relax"
    if (std::regex_search(input, match, std::regex(R"(i need to relax)", std::regex::icase))) {
        return "What would help you relax right now?";
    }

    // Pattern 6: "I am/I'm tired"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) tired)", std::regex::icase))) {
        return "What has been wearing you out lately?";
    }

    // Pattern 7: "I am/I'm stressed"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) stressed)", std::regex::icase))) {
        return "What is the biggest source of your stress right now?";
    }

    // Pattern 8: "I feel great/good today"
    if (std::regex_search(input, match, std::regex(R"(i feel (?:great|good) today)", std::regex::icase))) {
        return "What has made today feel so good?";
    }

    return "";
}
