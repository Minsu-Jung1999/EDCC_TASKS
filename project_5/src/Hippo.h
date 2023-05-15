/*
 * This file defines the class Hippo, which is a derived class of Critter.
*/
#ifndef HIPPO_H
#define HIPPO_H



#include "Critter.h"

class Hippo : public Critter {
private:
    bool fullness; // Indicates if the hippo is full
    int randomDirection; // Holds a random direction value
    int moveAmount; // Holds the amount of movement
    int hungerTimes; // Keeps track of the hunger times
public:
    Hippo(int hunger); // Constructor that takes a hunger parameter
    virtual bool eat() override; // Overrides the eat() function from the base class
    virtual Attack fight(std::string opponent) override; // Overrides the fight() function from the base class
    virtual std::string getColor() override; // Overrides the getColor() function from the base class
    virtual Direction getMove() override; // Overrides the getMove() function from the base class
    virtual std::string getType() const override; // Overrides the getType() function from the base class
    virtual std::string toString() override; // Overrides the toString() function from the base class
};
#endif // HIPPO_H
