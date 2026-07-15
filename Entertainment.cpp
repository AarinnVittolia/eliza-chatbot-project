#include "Entertainment.h"
#include "TextUtils.h"
#include <regex>

std::string Entertainment::respond(const std::string& input) const {
    std::smatch match;

    // Pattern 1: "I went to a concert"
    if (std::regex_search(input, match, std::regex(R"(i went to a concert)", std::regex::icase))) {
        return "Who did you see play at the concert?";
    }

    // Pattern 2: "I like/love movies"
    if (std::regex_search(input, match, std::regex(R"(i (?:like|love) movies)", std::regex::icase))) {
        return "What kind of movies do you enjoy most?";
    }

    // Pattern 3: "I went/go dancing"
    if (std::regex_search(input, match, std::regex(R"(i (?:went|go) dancing)", std::regex::icase))) {
        return "What do you enjoy most about dancing?";
    }

    // Pattern 4: "I am/I'm going to a restaurant"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) going to a restaurant)", std::regex::icase))) {
        return "What kind of food are you in the mood for?";
    }

    // Pattern 5: "I went/go to a bar"
    if (std::regex_search(input, match, std::regex(R"(i (?:went|go) to a bar)", std::regex::icase))) {
        return "Who did you go to the bar with?";
    }

    // Pattern 6: "I watched <something>"
    if (std::regex_search(input, match, std::regex(R"(i watched (.+))", std::regex::icase))) {
        return "What did you think of " + TextUtils::reflect(match[1].str()) + "?";
    }

    // Pattern 7: "I am/I'm bored"
    if (std::regex_search(input, match, std::regex(R"(i(?:'m| am) bored)", std::regex::icase))) {
        return "What would you rather be doing right now?";
    }

    // Pattern 8: "I had fun <something>"
    if (std::regex_search(input, match, std::regex(R"(i had fun (.+))", std::regex::icase))) {
        return "What made " + TextUtils::reflect(match[1].str()) + " so fun?";
    }

    return "";
}
