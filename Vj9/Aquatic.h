#ifndef AQUATIC_H
#define AQUATIC_H

#include "Animal.h"

using namespace std;

class Aquatic : virtual public Animal {
protected:
    double maxDiveDepth;

public:
    Aquatic(string name, int age, double weight, double maxDiveDepth);
};

#endif

