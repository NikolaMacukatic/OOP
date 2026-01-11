#include "Mammal.h"
#include <iostream>

using namespace std;

Mammal::Mammal(string name, int age, double weight, bool hasFur)
    : Animal(name, age, weight), hasFur(hasFur)
{
    if (hasFur)
        cout << "Stvoren sisavac s dlakom\n";
    else
        cout << "Stvoren sisavac s malo dlake\n";
}
