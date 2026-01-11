#include "Elephant.h"
#include <stdexcept>

using namespace std;

Elephant::Elephant(string name, int age, double weight)
    : Animal(name, age, weight), Mammal(name, age, weight, false) {
}

string Elephant::getSpecies() const
{
    return "Elephant";
}

double Elephant::getDailyFood() const
{
    double food = weight * 0.04;
    if (food == 0)
        throw logic_error("No food");
    return food;
}

string Elephant::getName() const
{
    return name;
}
