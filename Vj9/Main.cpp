#include <iostream>
#include "ZooSection.h"
#include "ZooKeeper.h"
#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeaTurtle.h"

using namespace std;

int main()
{
    try {
        ZooSection<Animal> section;
        ZooKeeper keeper;

        section.addAnimal(make_unique<Lion>("Simba", 5, 190));
        section.addAnimal(make_unique<Elephant>("Dumbo", 10, 1200));
        section.addAnimal(make_unique<Dolphin>("Flipper", 7, 300));
        section.addAnimal(make_unique<SeaTurtle>("Leonardo", 80, 150));

        for (size_t i = 0; i < section.size(); i++)
            keeper.processAnimal(section.getAnimal(i));

        cout << section.totalFood() << "\n";
        cout << ZooKeeper::getTotalAnimalsServed() << "\n";
    }
    catch (exception& e) {
        cout << e.what() << "\n";
    }
}
