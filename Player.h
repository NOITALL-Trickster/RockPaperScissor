#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Entity.h"

class Player {
	std::string name;
	Entity* chosenEntity;
	int score;
public:
	Player(const std::string&);
	Player() {};
	~Player();

	void setName(const std::string&);
	void setScore(int);
	void setEntity(Entity*);

	Entity* getEnitity()const;
	std::string getName()const;
	int getScore()const;

};

#endif

