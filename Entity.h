#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>


class Entity {
	std::string name;
	std::vector<Entity *> *killable;
	static std::vector<Entity*> totalEntityList;
public:
	Entity();
	Entity(const std::string&);
	Entity(std::vector<Entity*>*);
	Entity(const std::string&, std::vector<Entity*>*);
	~Entity();
	
	void setName(const std::string&);
	void setKillable(std::vector<Entity*>*);
	
	std::string getName() const;
	std::vector<Entity*>* getKillable() const;
	static std::vector<Entity*> getTotalEntities();
	void appendToKillable(Entity*);
};

#endif

