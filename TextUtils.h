#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#include <string>

// Small set of free functions shared by every major functionality
// component. None of these belong to a single component, so they live
// here instead of being duplicated in each .cpp file.
namespace TextUtils {

    // Returns a lowercase copy of the given string.
    std::string toLower(const std::string& text);

    // Removes leading/trailing whitespace from the given string.
    std::string trim(const std::string& text);

    // Performs the classic ELIZA "reflection" transform: swaps first and
    // second person pronouns so that captured user text can be echoed
    // back naturally (e.g. "my mother" becomes "your mother").
    std::string reflect(const std::string& fragment);

}

#endif // TEXT_UTILS_H
