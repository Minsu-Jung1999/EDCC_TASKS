// This is the header file for the Bird class, a derived class of Critter.
// Bird class simulates a Bird in a game or simulation.


#ifndef BIRD_H
#define BIRD_H


#include "Critter.h"


class Bird : public Critter
{
private:
    int direction; // Indicates the current direction of the bird.
    int iteration; // Indicates the number of times the bird has moved in the current direction.
    Direction Edirection; // Indicates the direction of the bird's eyes.


public:
    Bird(); // Constructor that initializes direction, iteration, and eye direction.
    virtual bool eat() override; // Determines whether the bird ate and returns the result.
    virtual Attack fight(std::string opponent) override; // Determines the bird's attack against an opponent.
    virtual std::string getColor() override; // Returns the color of the bird as a string ("blue").
    virtual Direction getMove() override; // Determines the direction of the bird's move.
    virtual std::string getType() const override; // Returns the type of the bird as a string ("Bird").
    virtual std::string toString() override; // Returns a string representation of the bird.


};


#endif // BIRD_H
