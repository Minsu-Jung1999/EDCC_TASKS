/*
 * Minsu Jung
 * CS 132 Project 2
 * May 14
 *
 * This code defines an Ant class, which is a type of creature with specific behavior and attributes.
 * The Ant class has methods for eating, fighting, determining its type, converting its state to a string representation,
 * setting its move direction, and getting its color.
*/
#include "Ant.h"

// Constructor: Initialize the ant with its walk direction and set changeDirection to false
Ant::Ant(bool walkSouth) {
    this->walkSouth = walkSouth;
    changeDirection = false;
}

// Attempt to eat; always return true.
bool Ant::eat() {
    return true;
}

// Determine the ant's attack method; always use scratch.
Attack Ant::fight(std::string opponent) {
    return SCRATCH;
}

// Return the ant's type as a string ("Ant").
std::string Ant::getType() const {
    return "Ant";
}

// Convert the ant's state into a string representation; always return the same string for all ants.
std::string Ant::toString() {
    return "%";
}

// Determine the ant's move direction based on its walking pattern (S - E - S - E, or N - E - N - E).
Direction Ant::getMove() {
    changeDirection = !changeDirection;
    if (walkSouth)   // S - E - S - E .....
    {
        return changeDirection ? SOUTH : EAST;
    }
    else // N - E - N - E .....
    {
        return changeDirection ? NORTH : EAST;
    }
}

// Return the ant's color; always return "red" for all ants.
std::string Ant::getColor() {
    return "red";
}

