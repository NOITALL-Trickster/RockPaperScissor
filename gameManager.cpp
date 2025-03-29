#include "gameManager.h"

GameManager::GameManager(const int& outof, const int& scoreincrement, bool multi = true) {
	outOf = outof;
	scoreIncrement = scoreincrement;
	multiplayer = multi;
}

void GameManager::setOutOf(int val) {
	outOf = val;
}
void GameManager::setScoreIncrement(int val) {
	scoreIncrement = val;
}

int GameManager::getOutOf() const {
	return outOf;
}
int GameManager::getScoreIncrement() const {
	return scoreIncrement;
}

bool GameManager::canItKill(Entity* e1, Entity* e2) {
	auto it = std::find_if(e1->getKillable()->begin(), e1->getKillable()->end(), [&](const Entity* e) {
		return e->getName() == e2->getName();
		});

	return it != e1->getKillable()->end();
}

bool GameManager::getMultiplayer()const {
	return multiplayer;
}

void GameManager::displayScore(Player& p1, Player& p2) const {
	std::cout << "Player " << p1.getName() << " scores: " << p1.getScore() << std::endl;
	std::cout << "Player " << p2.getName() << " scores: " << p2.getScore() << std::endl;
};

void GameManager::incrementScore(Player& p1, Player& p2) {
	if (p1.getEntity()->getName() == p2.getEntity()->getName()) {
		std::cout << p1.getEntity()->getName() << " ties with " << p2.getEntity()->getName() << std::endl;
		std::cout << "Player " << p1.getName() << " ties with " << "player " << p2.getName() << std::endl;
	}
	else {
		if (canItKill(p1.getEntity(), p2.getEntity())) {
			std::cout << p1.getEntity()->getName() << " gobles " << p2.getEntity()->getName() << std::endl;
			std::cout << "Player " << p1.getName() << " beats " << "player " << p2.getName() << std::endl;
			p1.setScore(scoreIncrement);
		}
		else {
			std::cout << p2.getEntity()->getName() << " gobles " << p1.getEntity()->getName() << std::endl;
			std::cout << "Player " << p2.getName() << " beats " << "player " << p1.getName() << std::endl;
			p2.setScore(scoreIncrement);
		}
	}
}


void GameManager::chosePlayer(int playerChosed, std::vector<Entity *> entities, Player& player) {
	if (playerChosed > entities.size()) throw "no entity found";
	player.setEntity(entities[playerChosed]);
}

void GameManager::displayEntities(std::vector<Entity*> ent)const {
	size_t count = 0;
	for (auto x : ent) {
		std::cout << std::setw(15) << std::right << "Enter [" << count++ << "] for " << x->getName() << std::endl;
	}
}

int GameManager::assignRandomEntity(std::vector<Entity*> elist) {
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<int> dist(1, elist.size()-1);
	return dist(gen);
}

void GameManager::displayWinner(Player& p1, Player& p2) {
	std::cout << std::endl;
	std::cout << "Winner IS " << std::endl;
	std::cout << std::endl;
	GameManager::displayScore(p1, p2);
	std::cout << std::endl;
	if (p1.getScore() > p2.getScore()) {
		std::cout << "Player " << p1.getName() << " won!." << std::endl;
	}
	else {
		std::cout << "Player " << p2.getName() << " won!." << std::endl;
	}
}