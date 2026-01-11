#include "Dolphin.h"
#include <stdexcept>

using namespace std;

Dolphin::Dolphin(string name, int age, double weight)
    : Animal(name, age, weight),
    Mammal(name, age, weight, true),
    Aquatic(name, age, weight, 300.0) {
}

string Dolphin::getSpecies() const
{
    return "Dolphin";
}

double Dolphin::getDailyFood() const
{
    double food = weight * 0.05;
    if (food == 0)
        throw logic_error("No food");
    return food;
}

string Dolphin::getName() const
{
    return name;
}
