#ifndef GNOME_H
#define GNOME_H

#include "Enemy.h"
#include "Player.h"

class Gnome : public Enemy {
public:
    Gnome(std::string name);

    void attackPlayer(Player* target) override;
    void specialAbility() override;
    void displayStatus() const override;
};

#endif

