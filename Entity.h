#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

// Class representing an entity in the game, which can have a name and a list of entities it can defeat.
class Entity {
    std::string name; // Name of the entity
    std::vector<Entity*>* killable; // List of entities this entity can defeat
    static std::vector<Entity*> totalEntityList; // Static list of all entities in the game

public:
    // Constructors
    Entity(); // Default constructor
    Entity(const std::string&); // Constructor with name
    Entity(std::vector<Entity*>*); // Constructor with killable list
    Entity(const std::string&, std::vector<Entity*>*); // Constructor with name and killable list
    ~Entity(); // Destructor

    // Setters
    void setName(const std::string&); // Set entity name
    void setKillable(std::vector<Entity*>*); // Set list of entities this entity can defeat

    // Getters
    std::string getName() const; // Get entity name
    std::vector<Entity*>* getKillable() const; // Get list of entities this entity can defeat
    static std::vector<Entity*> getTotalEntities(); // Get list of all entities

    // Add an entity to the killable list
    void appendToKillable(Entity*);
};

#endif
