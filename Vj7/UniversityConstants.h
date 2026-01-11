#ifndef UNIVERSITYCONSTANTS_H
#define UNIVERSITYCONSTANTS_H

#include <iostream>

struct UniversityConstants {
    static constexpr int MAX_ETCS_PER_YEAR = 60;
    static constexpr int REQUIRED_ECTS_PER_YEAR = 45;

    static void print_university_rules() {
        std::cout << "MAX_ETCS_PER_YEAR = " << MAX_ETCS_PER_YEAR << "\n";
        std::cout << "REQUIRED_ECTS_PER_YEAR = " << REQUIRED_ECTS_PER_YEAR << "\n";
    }
};

#endif

