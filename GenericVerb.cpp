#include "GenericVerb.h"
#include "TextUtils.h"
#include <regex>

std::string GenericVerb::respond(const std::string& input) const {
    std::smatch match;

    // Pattern 1: "I have <something>"
    if (std::regex_search(input, match, std::regex(R"(i have (.+))", std::regex::icase))) {
        return "How long have you had " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 2: "I bought/purchased <something>"
    if (std::regex_search(input, match, std::regex(R"(i (?:bought|purchased) (.+))", std::regex::icase))) {
        return "What made you decide to purchase " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 3: "I want to travel to <place>"
    if (std::regex_search(input, match, std::regex(R"(i want to travel to (.+))", std::regex::icase))) {
        return "What draws you to " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 4: "I don't/do not know <something>"
    if (std::regex_search(input, match, std::regex(R"(i (?:don't|do not) know (.+))", std::regex::icase))) {
        return "What would it take for you to know " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 5: "I know <something>"
    if (std::regex_search(input, match, std::regex(R"(i know (.+))", std::regex::icase))) {
        return "How do you know " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 6: "I am/I'm learning <something>"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) learning (.+))", std::regex::icase))) {
        return "What has learning " + TextUtils::reflect(match[1].str()) + " been like for you?";
    }

    // Pattern 7: "I need <something>"
    if (std::regex_search(input, match, std::regex(R"(i need (.+))", std::regex::icase))) {
        return "Why do you need " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 8: "I want <something>"
    if (std::regex_search(input, match, std::regex(R"(i want (.+))", std::regex::icase))) {
        return "What would it mean to you to have " + TextUtils::reflect(match[1].str()) + "?";
    }

    return "";
}
