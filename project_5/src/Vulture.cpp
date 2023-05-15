/*
 * Minsu Jung
 * CS 132 Project 2
 * May 14
 *
 * These are implementations of the Hippo and Vulture classes, which are used to simulate the behavior of animals in a game or simulation.
 * Each class has member functions that determine how the animal behaves when it is hungry or fighting against an opponent
*/
#include "Vulture.h"

// Constructor: Initialize the state of the vulture as being hungry.
Vulture::Vulture() {
    hungry = true;
}

// Determine whether the vulture can eat and update its state accordingly.
bool Vulture::eat() {
    if(!hungry) // already ate
    {
        return false;
    }
    else {
        hungry = false;
        return true;
    }
}

// Decide the vulture's attack method based on its hunger state and opponent type.
Attack Vulture::fight(std::string opponent) {
    if(!hungry)
    {
        hungry = true;
    }
    if(opponent == "%") // attack hippo with roar if not hungry
    {
        return ROAR;
    }
    else
    {
        return POUNCE; // attack other creatures with pounce
    }
}

// Get the type of the vulture as a string ("Vulture").
std::string Vulture::getType() const {
    return "Vulture";
}

// Get the color of the vulture as a string ("black").
std::string Vulture::getColor() {
    return "black";
}
