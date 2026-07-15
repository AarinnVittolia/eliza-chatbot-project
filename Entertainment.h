#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include <string>

// Handles user input about leisure activities: concerts, movies,
// dancing, restaurants, and bars.
class Entertainment {
public:
    std::string respond(const std::string& input) const;
};

#endif // ENTERTAINMENT_H
