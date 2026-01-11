#include "Player.h"

Player::Player(std::string name, int health)
    : GameCharacter(name, health), score(0) {
}

Player::~Player() {}

void Player::addScore(int value)
{
    score += value;
}
