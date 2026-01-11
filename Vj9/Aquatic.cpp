#include "Aquatic.h"
#include <iostream>

using namespace std;

Aquatic::Aquatic(string name, int age, double weight, double maxDiveDepth)
    : Animal(name, age, weight), maxDiveDepth(maxDiveDepth)
{
    cout << "Stvorena vodena zivotinja koja roni do " << maxDiveDepth << "m\n";
}
