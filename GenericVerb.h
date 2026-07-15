#ifndef GENERIC_VERB_H
#define GENERIC_VERB_H

#include <string>

// Handles user input built around common, everyday verbs: have,
// purchase, travel, know, learn, need, want. This component is the
// catch-all for ordinary statements that are not clearly about one of
// the more specific topics (love, money, school, etc).
class GenericVerb {
public:
    // Attempts to match the input against this component's patterns.
    // Returns a response string if a pattern matched, or an empty
    // string if none of this component's patterns apply.
    std::string respond(const std::string& input) const;
};

#endif // GENERIC_VERB_H
