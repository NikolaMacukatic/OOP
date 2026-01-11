#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Mammal.h"

using namespace std;

class Elephant : public Mammal {
public:
    Elephant(string name, int age, double weight);

    string getSpecies() const override;
    double getDailyFood() const override;
    string getName() const override;
};

#endif
