#include "TextUtils.h"
#include <regex>
#include <vector>
#include <utility>
#include <cctype>

namespace TextUtils {

    std::string toLower(const std::string& text) {
        std::string result = text;
        for (char& c : result) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
        return result;
    }

    std::string trim(const std::string& text) {
        size_t start = 0;
        size_t end = text.size();
        while (start < end && std::isspace(static_cast<unsigned char>(text[start]))) {
            start++;
        }
        while (end > start && std::isspace(static_cast<unsigned char>(text[end - 1]))) {
            end--;
        }
        return text.substr(start, end - start);
    }

    // Reflection swaps first- and second-person pronouns so captured
    // user text can be echoed back naturally (e.g. "my mother"
    // becomes "your mother"). This is done in two regex_replace()
    // passes so a word is never swapped back a second time:
    //   Pass 1 maps each recognized word/phrase to a unique numeric
    //   placeholder token (e.g. "i am" -> "@@1@@").
    //   Pass 2 maps each placeholder token to its final word
    //   (e.g. "@@1@@" -> "you are").
    // The placeholder tokens are purely numeric so they can never be
    // accidentally re-matched by the word-based patterns in pass 1.
    std::string reflect(const std::string& fragment) {
        std::string text = fragment;

        // Pass 1: word/phrase -> placeholder. Multi-word phrases are
        // listed before the single words they contain so "i am" is
        // swapped as a unit before the lone "i" or "am" rules can fire.
        static const std::vector<std::pair<std::regex, std::string>> toPlaceholder = {
            {std::regex(R"(\bi'm\b)", std::regex::icase),        "@@1@@"},
            {std::regex(R"(\bi am\b)", std::regex::icase),       "@@1@@"},
            {std::regex(R"(\byou're\b)", std::regex::icase),     "@@2@@"},
            {std::regex(R"(\byou are\b)", std::regex::icase),    "@@2@@"},
            {std::regex(R"(\bmyself\b)", std::regex::icase),     "@@3@@"},
            {std::regex(R"(\byourself\b)", std::regex::icase),   "@@4@@"},
            {std::regex(R"(\bmine\b)", std::regex::icase),       "@@5@@"},
            {std::regex(R"(\byours\b)", std::regex::icase),      "@@6@@"},
            {std::regex(R"(\bmy\b)", std::regex::icase),         "@@7@@"},
            {std::regex(R"(\byour\b)", std::regex::icase),       "@@8@@"},
            {std::regex(R"(\bme\b)", std::regex::icase),         "@@9@@"},
            {std::regex(R"(\bi\b)", std::regex::icase),          "@@9@@"},
            {std::regex(R"(\byou\b)", std::regex::icase),        "@@10@@"},
            {std::regex(R"(\bam\b)", std::regex::icase),         "@@11@@"},
            {std::regex(R"(\bare\b)", std::regex::icase),        "@@12@@"}
        };
        for (const auto& rule : toPlaceholder) {
            text = std::regex_replace(text, rule.first, rule.second);
        }

        // Pass 2: placeholder -> final word.
        static const std::vector<std::pair<std::regex, std::string>> toFinalWord = {
            {std::regex(R"(@@1@@)"),  "you are"},
            {std::regex(R"(@@2@@)"),  "i am"},
            {std::regex(R"(@@3@@)"),  "yourself"},
            {std::regex(R"(@@4@@)"),  "myself"},
            {std::regex(R"(@@5@@)"),  "yours"},
            {std::regex(R"(@@6@@)"),  "mine"},
            {std::regex(R"(@@7@@)"),  "your"},
            {std::regex(R"(@@8@@)"),  "my"},
            {std::regex(R"(@@9@@)"),  "you"},
            {std::regex(R"(@@10@@)"), "i"},
            {std::regex(R"(@@11@@)"), "are"},
            {std::regex(R"(@@12@@)"), "am"}
        };
        for (const auto& rule : toFinalWord) {
            text = std::regex_replace(text, rule.first, rule.second);
        }

        return text;
    }

}
