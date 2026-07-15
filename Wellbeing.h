#ifndef WELLBEING_H
#define WELLBEING_H

#include <string>

// Handles user input about physical and mental wellbeing: exercise,
// vitamins, relaxing, sleeping, stress, and being tired.
class Wellbeing {
public:
    std::string respond(const std::string& input) const;
};

#endif // WELLBEING_H
