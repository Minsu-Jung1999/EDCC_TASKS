/*
 * This file defines the class Vulture, which is a derived class of Bird.
*/

#ifndef VULTURE_H
#define VULTURE_H



#include "Bird.h"

class Vulture : public Bird {
private:
    bool hungry; // Indicates if the vulture is hungry
public:
    Vulture(); // Default constructor
    virtual bool eat() override; // Overrides the eat() function from the base class
    virtual Attack fight(std::string opponent) override; // Overrides the fight() function from the base class
    virtual std::string getColor() override; // Overrides the getColor() function from the base class
    virtual std::string getType() const override; // Overrides the getType() function from the base class
};

#endif // VULTURE_H
