#include "Financial.h"
#include "TextUtils.h"
#include <regex>

std::string Financial::respond(const std::string& input) const {
    std::smatch match;

    // Pattern 1: "I don't/do not have (enough) money"
    if (std::regex_search(input, match, std::regex(R"(i (?:don't|do not) have (?:enough )?money)", std::regex::icase))) {
        return "What is it about your money situation that concerns you most?";
    }

    // Pattern 2: "I am/I'm in debt"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) in debt)", std::regex::icase))) {
        return "How did you end up in debt?";
    }

    // Pattern 3: "my savings <something>"
    if (std::regex_search(input, match, std::regex(R"(my savings (.+))", std::regex::icase))) {
        return "How do you feel about the fact that your savings " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 4: "I invested in <something>"
    if (std::regex_search(input, match, std::regex(R"(i invested in (.+))", std::regex::icase))) {
        return "What made you decide to invest in " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 5: "I am/I'm worried about bankruptcy"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) worried about bankruptcy)", std::regex::icase))) {
        return "What is driving your worry about bankruptcy?";
    }

    // Pattern 6: "I need money"
    if (std::regex_search(input, match, std::regex(R"(i need money)", std::regex::icase))) {
        return "What do you need the money for?";
    }

    // Pattern 7: "I lost my job"
    if (std::regex_search(input, match, std::regex(R"(i lost my job)", std::regex::icase))) {
        return "How has losing your job affected you?";
    }

    // Pattern 8: "I want/need to save <something>"
    if (std::regex_search(input, match, std::regex(R"(i (?:want|need) to save (.+))", std::regex::icase))) {
        return "What are you hoping to do once you have saved " + TextUtils::reflect(match[1].str()) + "?";
    }

    return "";
}
