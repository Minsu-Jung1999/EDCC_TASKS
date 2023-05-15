#ifndef COUGAR_H
#define COUGAR_H

// This file defines the class Cougar, which is a derived class of Critter.

#include "Critter.h"

class Cougar : public Critter {
private:
    bool west; // Represents the direction the cougar is facing
    bool fought; // Indicates if the cougar has fought
public:
    Cougar(); // Default constructor
    virtual bool eat() override; // Overrides the eat() function from the base class
    virtual Attack fight(std::string opponent) override; // Overrides the fight() function from the base class
    virtual std::string getColor() override; // Overrides the getColor() function from the base class
    virtual Direction getMove() override; // Overrides the getMove() function from the base class
    virtual std::string getType() const override; // Overrides the getType() function from the base class
    virtual std::string toString() override; // Overrides the toString() function from the base class
};

#endif // COUGAR_H
