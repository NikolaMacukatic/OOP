#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include "Enemy.h"

class Warrior : public Player {
private:
    bool shieldActive;

public:
    Warrior(std::string name);

    void attackEnemy(Enemy* target) override;
    void specialAbility() override;
    void displayStatus() const override;
};

#endif

