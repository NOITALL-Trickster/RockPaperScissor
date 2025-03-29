#include <iostream>
#include <vector>
#include <string>
#include "Entity.h"
#include "gameManager.h"

int main() {
	GameManager manager(3, 5, false);
	
	Entity* rock = new Entity();
	Entity* paper = new Entity();
	Entity* scissors = new Entity();

	rock->setName("Rock");
	paper->setName("Paper");
	scissors->setName("Scissors");
	rock->appendToKillable(scissors);
	paper->appendToKillable(rock);
	scissors->appendToKillable(paper);
	


	Player* p1 = new Player();
	Player* p2 = new Player();
	std::string p1Name;
	std::string p2Name;

	if (manager.getMultiplayer()) {
		std::cout << "Enter player one name: ";
		std::cin >> p1Name;
		p1->setName(p1Name);
		std::cout << "Enter player two name: ";
		std::cin >> p2Name;
		p2->setName(p2Name);
	}
	else {
		std::cout << "Enter player one name: ";
		std::cin >> p1Name;
		p1->setName(p1Name);
		p2Name = "p2";
		p2->setName(p2Name);
	}

	unsigned count = 0;
	while (count < manager.getOutOf())
	{
		if (manager.getMultiplayer()) {
			std::cout << std::endl;
			std::cout << "Round " << 1+(count)++ << std::endl;
			std::cout << std::endl;
			
			manager.displayEntities(Entity::getTotalEntities());
			std::string c;
			std::cout << "Select an entity for " << p1->getName() << " : ";
			std::cin >> c;
			std::string x;
			std::cout << "Select an entity for  " << p2->getName() << " : ";
			std::cin >> x;
			manager.chosePlayer(std::stoi(c), Entity::getTotalEntities(), *p1);
			manager.chosePlayer(std::stoi(x), Entity::getTotalEntities(), *p2);
			manager.incrementScore(*p1, *p2);
			manager.displayScore(*p1, *p2);
		}
		else {
			std::cout << std::endl;
			std::cout << "Round " << 1 + (count)++ << std::endl;
			std::cout << std::endl;
			manager.displayEntities(Entity::getTotalEntities());
			std::string* c = new std::string();
			std::cout << "Select an entity for " << p1->getName() << " : ";
			std::cin >> *c;
			manager.chosePlayer(std::stoi(*c), Entity::getTotalEntities(), *p1);
			manager.chosePlayer(manager.assignRandomEntity(Entity::getTotalEntities()), Entity::getTotalEntities(), *p2);
			manager.incrementScore(*p1, *p2);
			manager.displayScore(*p1, *p2);
			delete c;
		}
	}

	manager.displayWinner(*p1,*p2);
	
}


/*
	TODO
	infinte players.
	ablity to save game and load from it.
*/
