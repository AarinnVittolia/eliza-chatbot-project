#ifndef CONCERN_H
#define CONCERN_H

#include <string>

// Handles user input that expresses anger, fear, or serious distress
// (keywords like hate, kill, suicide). Responses in this component
// stay supportive and open-ended, and statements suggesting the user
// may be in real distress get a gentler, more direct response rather
// than a purely reflective one.
class Concern {
public:
    std::string respond(const std::string& input) const;
};

#endif // CONCERN_H
