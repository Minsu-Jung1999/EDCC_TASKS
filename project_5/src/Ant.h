/*
 * Instructor : Alison Obourn
 *
 * This is the header file for the Ant class, a derived class of Critter.
 * Ant class simulates an Ant in a game or simulation.
*/


#ifndef ANT_H
#define ANT_H


#include "Critter.h"


class Ant : public Critter
{
private:
    bool walkSouth; // Indicates whether the ant walks south.
    bool changeDirection; // Indicates whether the ant can change direction.


public:
    Ant(bool walkSouth); // Constructor that sets the ant's direction to south.
    virtual bool eat() override; // Determines whether the ant ate and returns the result.
    virtual Attack fight(std::string opponent) override; // Determines the ant's attack against an opponent.
    virtual std::string getColor() override; // Returns the color of the ant as a string ("black").
    virtual Direction getMove() override; // Determines the direction of the ant's move.
    virtual std::string getType() const override; // Returns the type of the ant as a string ("Ant").
    virtual std::string toString() override; // Returns a string representation of the ant.


};


#endif // ANT_H
