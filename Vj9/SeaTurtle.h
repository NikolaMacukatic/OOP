#ifndef SEATURTLE_H
#define SEATURTLE_H

#include "Aquatic.h"

using namespace std;

class SeaTurtle : public Aquatic {
public:
    SeaTurtle(string name, int age, double weight);

    string getSpecies() const override;
    double getDailyFood() const override;
    string getName() const override;
};

#endif
