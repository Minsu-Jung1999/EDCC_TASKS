#include "Hippo.h"
#include <random>
#include <string>

/*
 * Minsu Jung
 * CS 132 Project 2
 * May 14
 *
 * The Hippo class represents a creature with specific behavior and attributes.
 * This class handles eating, fighting, determining its type, converting its state
 * to a string representation, setting its move direction, and getting its color.
 *
*/

// Constructor: Initialize the hippo with a hunger value and set its initial state.
Hippo::Hippo(int hunger) {
    fullness = (hunger == 0);
    randomDirection = 0;
    moveAmount = 0;
    hungerTimes = hunger;
}

// Determine whether the hippo eats, decrease hunger if not full, and update fullness state.
bool Hippo::eat() {
    if (hungerTimes == 0) {
        fullness = true;
    } else {
        hungerTimes--;
    }
    return !fullness;
}

// Decide the hippo's attack method based on its fullness state.
Attack Hippo::fight(std::string opponent) {
    if (fullness == false) {
        return SCRATCH;
    } else {
        return POUNCE;
    }
}

// Get the type of the hippo as a string ("Hippo").
std::string Hippo::getType() const {
    return "Hippo";
}

// Convert the hippo's state (hungerTimes) into a string representation.
std::string Hippo::toString() {
    return std::to_string(hungerTimes);
}

// Calculate the hippo's move direction, picking a new random direction after a certain number of moves.
Direction Hippo::getMove() {
    if (moveAmount == 0 || moveAmount == 5) {
        randomDirection = rand() % 4; // 0 ~ 3
        moveAmount = 0;
    }
    moveAmount++;
    switch (randomDirection) {
    case 0:
        return NORTH;
    case 1:
        return EAST;
    case 2:
        return SOUTH;
    case 3:
        return WEST;
    default:
        return CENTER;
    }
}

// Get the color of the hippo based on its hunger state (white if not hungry, gray otherwise).
std::string Hippo::getColor() {
    return hungerTimes == 0 ? "white" : "gray";
}
