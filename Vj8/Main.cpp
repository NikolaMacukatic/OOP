#include <iostream>
#include <vector>
#include "Warrior.h"
#include "Mage.h"
#include "Gnome.h"
#include "Boss.h"

int main()
{
    std::vector<GameCharacter*> characters;

    Warrior* Conan = new Warrior("Conan");
    Mage* Merlin = new Mage("Merlin");
    Gnome* Gnomeo = new Gnome("Gnomeo");
    Gnome* Sneaky = new Gnome("Sneaky");
    Boss* Dragon = new Boss("Dragon");

    characters.push_back(Conan);
    characters.push_back(Merlin);
    characters.push_back(Gnomeo);
    characters.push_back(Sneaky);
    characters.push_back(Dragon);

    Conan->attackEnemy(Gnomeo);
    Conan->displayStatus();
    Gnomeo->displayStatus();

    Merlin->attackEnemy(Sneaky);
    Merlin->displayStatus();
    Sneaky->displayStatus();

    Gnomeo->attackPlayer(Conan);
    Gnomeo->displayStatus();
    Conan->displayStatus();

    Merlin->attackEnemy(Gnomeo);
    Merlin->displayStatus();
    Gnomeo->displayStatus();

    Dragon->attackPlayer(Merlin);
    Dragon->displayStatus();
    Merlin->displayStatus();

    Merlin->attackEnemy(Gnomeo);
    Conan->attackEnemy(Dragon);
    Merlin->attackEnemy(Dragon);

    for (auto c : characters)
        c->specialAbility();

    GameCharacter* maxHealth = nullptr;

    for (auto c : characters) {
        if (c->isAlive()) {
            c->displayStatus();
            if (!maxHealth || c->getHealth() > maxHealth->getHealth())
                maxHealth = c;
        }
    }

    if (maxHealth)
        std::cout << maxHealth->getName() << "\n";

    for (auto c : characters)
        delete c;
}
