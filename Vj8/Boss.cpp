#include "Boss.h"
#include <iostream>

Boss::Boss(std::string name)
    : Enemy(name, 300, 8) {
}

void Boss::attackPlayer(Player* target)
{
    if (!target || !target->isAlive())
        return;

    target->takeDamage(10 * difficulty);
}

void Boss::specialAbility()
{
    health += 50;
    if (health > 300)
        health = 300;
}

void Boss::displayStatus() const
{
    std::cout << name << " " << health << " " << difficulty << "\n";
}
