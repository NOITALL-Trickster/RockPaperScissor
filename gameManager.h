#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include<vector>
#include<algorithm>
#include <iostream>
#include <random>
#include <iomanip>
#include "Player.h"
#include "Entity.h"

// Class to manage game logic, including player scores, entity selection, and determining the winner.
class GameManager {
    int outOf; // Number of rounds (default: best of 3)
    int scoreIncrement; // Score increment multiplier based on times won
    bool multiplayer; // Flag to indicate if the game is multiplayer (default: true)

    // Helper function to check if one entity can eliminate another
    bool canItKill(Entity*, Entity*);

public:
    // Constructor to initialize the game settings
    GameManager(const int&, const int&, bool);

    // Setters for game parameters
    void setOutOf(int);  // Set number of rounds
    void setScoreIncrement(int); // Set score increment multiplier

    // Getters for game parameters
    int getOutOf() const;  // Get number of rounds
    int getScoreIncrement() const; // Get score increment multiplier
    bool getMultiplayer() const; // Get multiplayer flag

    // Increment the score of a player
    void incrementScore(Player&, Player&);

    // Display the current score of both players
    void displayScore(Player&, Player&) const;

    // Allow a player to choose an entity from a list
    void chosePlayer(int, std::vector<Entity*>, Player&);

    // Assign a random entity from a list
    int assignRandomEntity(std::vector<Entity*>);

    // Display available entities
    void displayEntities(std::vector<Entity*>) const;

    // Display the winner based on scores
    void displayWinner(Player&, Player&);
};

#endif
