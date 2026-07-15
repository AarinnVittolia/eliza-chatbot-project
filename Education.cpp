#include "Education.h"
#include "TextUtils.h"
#include <regex>

std::string Education::respond(const std::string& input) const {
    std::smatch match;

    // Pattern 1: "I am/I'm a student"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) a student)", std::regex::icase))) {
        return "What are you studying?";
    }

    // Pattern 2: "my courses <something>"
    if (std::regex_search(input, match, std::regex(R"(my courses (.+))", std::regex::icase))) {
        return "What part of your courses " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 3: "I am/I'm studying <something>"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) studying (.+))", std::regex::icase))) {
        return "What made you interested in studying " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 4: "I go to <school> university"
    if (std::regex_search(input, match, std::regex(R"(i go to (.+) university)", std::regex::icase))) {
        return "What do you like most about " + TextUtils::reflect(match[1].str()) + " University?";
    }

    // Pattern 5: "I failed <something>"
    if (std::regex_search(input, match, std::regex(R"(i failed (.+))", std::regex::icase))) {
        return "How did it feel to fail " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 6: "I am/I'm worried about (my) education"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) worried about (?:my )?education)", std::regex::icase))) {
        return "What about your education is worrying you?";
    }

    // Pattern 7: "I have an exam <something>"
    if (std::regex_search(input, match, std::regex(R"(i have an exam (.+))", std::regex::icase))) {
        return "How are you feeling about the exam " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 8: "I graduated <something>"
    if (std::regex_search(input, match, std::regex(R"(i graduated (.+))", std::regex::icase))) {
        return "How do you feel now that you graduated " + TextUtils::reflect(match[1].str()) + "?";
    }

    return "";
}
