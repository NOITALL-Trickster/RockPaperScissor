#include "Entity.h"


std::vector<Entity*> Entity::totalEntityList;

Entity::Entity() {
	name = "None";
	killable = new std::vector<Entity *>();
}
Entity::Entity(const std::string& n):Entity() {
	this->setName(n);
	name = n;
}
Entity::Entity(std::vector<Entity*>* kill):Entity() {
	killable = kill;
}

Entity::Entity(const std::string& n, std::vector<Entity*>* kill) :Entity() {
	this->setName(n);
	killable = kill;
}

Entity::~Entity() {
	for (auto del : *killable) {
		delete del;
	}
	delete[] killable;
}

void Entity::setName(const std::string& n) {
	name = n;
	totalEntityList.push_back(this);
}
void Entity::setKillable(std::vector<Entity*>* kill) {
	killable = kill;
}

std::string Entity::getName() const {
	return name;
}

std::vector<Entity*>* Entity::getKillable() const {
	return killable;
}

std::vector<Entity*> Entity::getTotalEntities() {
	return totalEntityList;
}

void Entity::appendToKillable(Entity* e1) {
	killable->push_back(e1);
}