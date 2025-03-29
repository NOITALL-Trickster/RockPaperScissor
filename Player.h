#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Entity.h"

// Class representing a player in the game, with a name, chosen entity, and score.
class Player {
    std::string name; // Player's name
    Entity* chosenEntity; // The entity chosen by the player
    int score; // Player's score

public:
    // Constructors
    Player(const std::string&); // Constructor with name
    Player() {}; // Default constructor
    ~Player(); // Destructor

    // Setters
    void setName(const std::string&); // Set player name
    void setScore(int); // Set player score
    void setEntity(Entity*); // Set chosen entity

    // Getters
    Entity* getEnitity() const; // Get chosen entity (note: typo in method name)
    std::string getName() const; // Get player name
    int getScore() const; // Get player score
};

#endif