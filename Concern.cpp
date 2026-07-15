#include "Concern.h"
#include "TextUtils.h"
#include <regex>

std::string Concern::respond(const std::string& input) const {
    std::smatch match;

    // Pattern 1: statements naming suicide directly. This is checked
    // first and gets a distinct, more grounded response rather than a
    // purely reflective ELIZA-style question.
    if (std::regex_search(input, match,
            std::regex(R"(suicide|kill myself|end my life)", std::regex::icase))) {
        return "That sounds like a lot to carry. If this feeling is serious, please "
               "talk to someone you trust or a mental health professional. What has "
               "been making things feel this heavy?";
    }

    // Pattern 2: "I want to kill <someone/something>"
    if (std::regex_search(input, match, std::regex(R"(i want to kill (.+))", std::regex::icase))) {
        return "What has " + TextUtils::reflect(match[1].str()) + " done that makes you feel this way?";
    }

    // Pattern 3: "I hate <something>"
    if (std::regex_search(input, match, std::regex(R"(i hate (.+))", std::regex::icase))) {
        return "What is it about " + TextUtils::reflect(match[1].str()) + " that bothers you so much?";
    }

    // Pattern 4: "I am/I'm angry <about something>"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) angry (.+))", std::regex::icase))) {
        return "What is making you feel angry about " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 5: "I am/I'm scared of <something>"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) scared of (.+))", std::regex::icase))) {
        return "What about " + TextUtils::reflect(match[1].str()) + " scares you the most?";
    }

    // Pattern 6: "I can't/cannot stand <something>"
    if (std::regex_search(input, match, std::regex(R"(i (?:can't|cannot) stand (.+))", std::regex::icase))) {
        return "How long has " + TextUtils::reflect(match[1].str()) + " been bothering you?";
    }

    // Pattern 7: "everyone hates me"
    if (std::regex_search(input, match, std::regex(R"(everyone hates me)", std::regex::icase))) {
        return "What makes you feel that everyone hates you?";
    }

    // Pattern 8: "I am/I'm worried about <something>"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) worried about (.+))", std::regex::icase))) {
        return "What part of " + TextUtils::reflect(match[1].str()) + " worries you?";
    }

    return "";
}
