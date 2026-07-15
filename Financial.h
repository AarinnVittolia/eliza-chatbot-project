#ifndef FINANCIAL_H
#define FINANCIAL_H

#include <string>

// Handles user input about money, savings, investments, and
// bankruptcy-related topics.
class Financial {
public:
    std::string respond(const std::string& input) const;
};

#endif // FINANCIAL_H
