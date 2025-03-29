#include "Player.h"

Player::Player(const std::string& n) {
	name = n;
	score = 0;
	chosenEntity = nullptr;
}

Player::~Player() {
	delete chosenEntity;
}

void Player::setName(const std::string& n) {
	name = n;
}
void Player::setScore(int val) {
	score += val;
}
std::string Player::getName()const {
	return name;
}
int Player::getScore()const {
	return score;
}

void Player::setEntity(Entity* e) {
	chosenEntity = e;
}

Entity* Player::getEntity()const {
	return chosenEntity;
}



