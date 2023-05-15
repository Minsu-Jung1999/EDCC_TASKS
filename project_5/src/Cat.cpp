/*
 * Minsu Jung
 * CS 132 Project 2
 * May 14
 *
 * This code defines a Cat class which represents a cat in a simulation. The cat can have different states and make various moves(Random direction and Random Moveamount)
 * , defined by the following member functions.
*/
#include "Cat.h"
#include <random>

// Constructor: Initialize the cat with random direction and move amount.
Cat::Cat() {
    randomDirection = 0;
    randomMoveAmount = 0;
}

// Attempt to eat; always return true.
bool Cat::eat() {
    return true;
}

// Return the cat's type as a string ("Cat").
std::string Cat::getType() const {
    return "Cat";
}

// Determine the cat's attack method (pounce, roar, or scratch) based on a random choice when fighting an opponent.
Attack Cat::fight(std::string opponent) {
    int choice = rand() % 3; // 0 ~ 2
    switch(choice)
    {
    case 0:
        return POUNCE;
        break;
    case 1:
        return ROAR;
        break;
    default:            // case of 2 will return SCRATCH.
        return SCRATCH;
        break;
    }
}

// Convert the cat's state into a string representation based on its current state (e.g., asleep, awake, winning, mating, etc.).
std::string Cat::toString() {

    switch(E_State)
    {
    case 0:
        return "@";
        break;
    case 1:
        return "z";
        break;
    case 2:
        return "!";
        break;
    case 3:
        return "W";
        break;
    case 4:
        return "_";
        break;
    default:
        return "@";
        break;

    }
}

// Returns the cat's move direction (north, east, south, west, or center) based on a random direction and move amount.
Direction Cat::getMove() {
    if(randomMoveAmount == 0)
    {
        randomDirection = rand() % 4; // 0 ~ 3
        randomMoveAmount  = rand() % MAXAMOUNT + 1; // 1 ~ MAXAMOUNT+1(11)
    }
    randomMoveAmount--;
    switch(randomDirection)
    {
    case 0:
        return NORTH;
        break;
    case 1:
        return EAST;
        break;
    case 2:
        return SOUTH;
        break;
    case 3:
        return WEST;
        break;
    default:
        return CENTER;
        break;
    }

}

// Returns the cat's color according to its current state.
std::string Cat::getColor() {
    switch(E_State)
    {
    case 0:
        return "orange";
        break;
    case 1:
        return "green";
        break;
    case 2:
        return "red";
        break;
    case 3:
        return "blue";
        break;
    case 4:
        return "red";
        break;
    default:
        return "orange";
        break;

    }
}

// Change the cat's state to the losing state.
void Cat::onLose() {
    E_State = LOSE;
}

// Change the cat's state to the mating state.
void Cat::onMate() {
    E_State = MATE;
}

// Change the cat's state back to default after mating.
void Cat::onMateEnd() {
    E_State = DEFAULT;
}

// Change the cat's state to the sleeping state.
void Cat::onSleep() {
    E_State = SLEEP;
}

// Change the cat's state back to default after waking up.
void Cat::onWakeUp() {
    E_State = DEFAULT;
}

// Change the cat's state to the winning state.
void Cat::onWin() {
    E_State = WIN;
}
