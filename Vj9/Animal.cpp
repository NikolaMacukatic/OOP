#include "Animal.h"
#include <stdexcept>

using namespace std;

Animal::Animal(string name, int age, double weight)
    : name(name), age(age), weight(weight)
{
    if (name.empty() || age < 0 || weight <= 0)
        throw invalid_argument("Invalid animal data");
}

Animal::~Animal() {}
