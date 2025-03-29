#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include<vector>
#include<algorithm>
#include <iostream>
#include <random>
#include <iomanip>
#include "Player.h"
#include "Entity.h"

class GameManager {
	int outOf; // best of 3 by default
	int scoreIncrement; // times timesWon
	bool multiplayer; // default true;
	bool canItKill(Entity*, Entity*);

public:
	GameManager(const int&, const int&,bool);

	void setOutOf(int);
	void setScoreIncrement(int);

	int getOutOf() const;
	int getScoreIncrement() const;
	bool getMultiplayer() const;
	void incrementScore(Player&, Player&);
	void displayScore(Player&, Player&) const;
	void chosePlayer(int, std::vector<Entity *>, Player&);
	int assignRandomEntity(std::vector<Entity*>);
	void displayEntities(std::vector<Entity *>)const;
	void displayWinner(Player&,Player&);
};

#endif