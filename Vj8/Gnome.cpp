#include "Gnome.h"
#include <iostream>

Gnome::Gnome(std::string name)
    : Enemy(name, 90, 3) {
}

void Gnome::attackPlayer(Player* target)
{
    if (!target || !target->isAlive())
        return;

    target->takeDamage(5 * difficulty);
}

void Gnome::specialAbility()
{
    if (health > 20)
        std::cout << name << " blows the horn\n";
}

void Gnome::displayStatus() const
{
    std::cout << name << " " << health << " " << difficulty << "\n";
}
