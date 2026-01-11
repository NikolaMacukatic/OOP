#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal {
protected:
    string name;
    int age;
    double weight;

    Animal(string name, int age, double weight);

public:
    virtual ~Animal();

    virtual string getSpecies() const = 0;
    virtual double getDailyFood() const = 0;
    virtual string getName() const = 0;
};

#endif
