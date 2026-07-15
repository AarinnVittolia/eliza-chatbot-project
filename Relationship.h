#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include <string>

// Handles user input about love and relationships: love, spouse,
// girlfriend, boyfriend, breakups, and related feelings.
class Relationship {
public:
    std::string respond(const std::string& input) const;
};

#endif // RELATIONSHIP_H
