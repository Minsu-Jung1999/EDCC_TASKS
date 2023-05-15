/*
 * Minsu Jung
 * CS 132 Project 2
 * May 14
 *
 * This code defines a Cougar class, which is a type of creature with specific behavior and attributes.
 * The Cougar class has methods for eating, fighting, determining its type, converting its state to a string representation,
 * setting its move direction, and getting its color.
*/
#include "Cougar.h"

// Constructor: Initialize the cougar with the direction set to West and fought status set to false.
Cougar::Cougar() {
    west = true;
    fought = false;
}

// Attempt to eat; always return true and toggle the west flag.
bool Cougar::eat() {
    west = !west;
    return true;
}

// Determine the cougar's attack method; always use the "POUNCE" attack method.
Attack Cougar::fight(std::string opponent) {
    fought = true;
    return POUNCE;
}

// Return the cougar's type as a string ("Cougar").
std::string Cougar::getType() const {
    return "Cougar";
}

// Convert the cougar's state into a string representation; always use the same string for all cougars.
std::string Cougar::toString() {
    return "C";
}

// Determine the cougar's move direction based on the value of the west flag.
Direction Cougar::getMove() {
    return west ? WEST : EAST;
}

// Return the cougar's color; blue if cougar has not fought, red otherwise.
std::string Cougar::getColor() {
    return fought ? "red" : "blue";
}

