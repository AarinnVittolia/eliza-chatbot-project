#include "TextUtils.h"
#include <sstream>
#include <cctype>
#include <unordered_map>
#include <vector>

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

    // Reflection is done in two passes so that a word does not get
    // swapped twice (e.g. "i" -> "you" -> "i" again). The first pass
    // maps every recognized pronoun to a unique placeholder token, and
    // the second pass turns each placeholder into the final word.
    std::string reflect(const std::string& fragment) {
        static const std::unordered_map<std::string, std::string> toPlaceholder = {
            {"i", "@YOU@"},        {"me", "@YOU@"},       {"my", "@YOUR@"},
            {"mine", "@YOURS@"},   {"myself", "@YOURSELF@"},
            {"am", "@ARE@"},
            {"you", "@I@"},        {"your", "@MY@"},      {"yours", "@MINE@"},
            {"yourself", "@MYSELF@"},
            {"are", "@AM@"}
        };
        static const std::unordered_map<std::string, std::string> toFinalWord = {
            {"@YOU@", "you"},     {"@YOUR@", "your"},     {"@YOURS@", "yours"},
            {"@YOURSELF@", "yourself"},
            {"@ARE@", "are"},
            {"@I@", "i"},         {"@MY@", "my"},         {"@MINE@", "mine"},
            {"@MYSELF@", "myself"},
            {"@AM@", "am"}
        };

        std::istringstream iss(fragment);
        std::vector<std::string> words;
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }

        // Phase 1: swap recognized words to placeholders, keeping any
        // trailing punctuation attached to the original word.
        for (std::string& w : words) {
            std::string lower = toLower(w);
            std::string trailingPunct;
            while (!lower.empty() && std::ispunct(static_cast<unsigned char>(lower.back()))) {
                trailingPunct = lower.back() + trailingPunct;
                lower.pop_back();
            }
            auto it = toPlaceholder.find(lower);
            if (it != toPlaceholder.end()) {
                w = it->second + trailingPunct;
            }
        }

        // Phase 2: swap placeholders to their final lowercase word.
        std::string result;
        for (std::string& w : words) {
            for (const auto& entry : toFinalWord) {
                size_t pos = w.find(entry.first);
                if (pos != std::string::npos) {
                    w.replace(pos, entry.first.size(), entry.second);
                }
            }
            if (!result.empty()) {
                result += " ";
            }
            result += w;
        }
        return result;
    }

}
