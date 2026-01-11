#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int difficulty)
    : GameCharacter(name, health), difficulty(difficulty) {
}

Enemy::~Enemy() {}
