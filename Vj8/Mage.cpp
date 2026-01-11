#include "Mage.h"
#include <iostream>

Mage::Mage(std::string name)
    : Player(name, 80), mana(100) {
}

void Mage::attackEnemy(Enemy* target)
{
    if (!target || !target->isAlive())
        return;

    if (mana >= 20) {
        target->takeDamage(40);
        mana -= 20;
    }
    else {
        target->takeDamage(20);
    }

    if (!target->isAlive())
        addScore(10);
}

void Mage::specialAbility()
{
    if (health > 50)
        std::cout << name << " teleports\n";
}

void Mage::displayStatus() const
{
    std::cout << name << " " << health << " " << mana << " " << score << "\n";
}
