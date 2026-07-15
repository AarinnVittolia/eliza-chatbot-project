#ifndef EDUCATION_H
#define EDUCATION_H

#include <string>

// Handles user input about school and education: courses,
// university, studying, being a student, exams, and graduation.
class Education {
public:
    std::string respond(const std::string& input) const;
};

#endif // EDUCATION_H
