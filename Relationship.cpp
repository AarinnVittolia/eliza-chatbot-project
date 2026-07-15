#include "Relationship.h"
#include "TextUtils.h"
#include <regex>

std::string Relationship::respond(const std::string& input) const {
    std::smatch match;

    // Pattern 1: "I don't/do not love <someone>"
    if (std::regex_search(input, match, std::regex(R"(i (?:don't|do not) love (.+))", std::regex::icase))) {
        return "What changed between you and " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 2: "I love <someone/something>"
    if (std::regex_search(input, match, std::regex(R"(i love (.+))", std::regex::icase))) {
        return "Tell me more about your feelings for " + TextUtils::reflect(match[1].str()) + ".";
    }

    // Pattern 3: "my girlfriend/boyfriend <does something>"
    if (std::regex_search(input, match, std::regex(R"(my (?:girlfriend|boyfriend) (.+))", std::regex::icase))) {
        return "How does it make you feel that " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 4: "my spouse <does something>"
    if (std::regex_search(input, match, std::regex(R"(my spouse (.+))", std::regex::icase))) {
        return "How long have you and your spouse dealt with " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 5: "I am/I'm in love with <someone>"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) in love with (.+))", std::regex::icase))) {
        return "What is it about " + TextUtils::reflect(match[1].str()) + " that draws you in?";
    }

    // Pattern 6: "I broke up with <someone>"
    if (std::regex_search(input, match, std::regex(R"(i broke up with (.+))", std::regex::icase))) {
        return "What led to the breakup with " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 7: "I miss <someone>"
    if (std::regex_search(input, match, std::regex(R"(i miss (.+))", std::regex::icase))) {
        return "What do you miss most about " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 8: "he/she loves/likes me"
    if (std::regex_search(input, match, std::regex(R"((?:he|she) (?:loves|likes) me)", std::regex::icase))) {
        return "How does it feel to know that?";
    }

    return "";
}
