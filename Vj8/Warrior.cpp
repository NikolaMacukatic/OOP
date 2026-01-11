#include "Warrior.h"
#include <iostream>

Warrior::Warrior(std::string name)
    : Player(name, 120), shieldActive(false) {
}

void Warrior::attackEnemy(Enemy* target)
{
    if (!target || !target->isAlive())
        return;

    target->takeDamage(20);

    if (!target->isAlive())
        addScore(10);
}

void Warrior::specialAbility()
{
    shieldActive = true;
}

void Warrior::displayStatus() const
{
    std::cout << name << " " << health << " " << score << "\n";
}
