#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

using namespace std;

class Mammal : virtual public Animal {
protected:
    bool hasFur;

public:
    Mammal(string name, int age, double weight, bool hasFur);
};

#endif

