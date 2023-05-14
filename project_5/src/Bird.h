
#ifndef BIRD_H
#define BIRD_H

#include "Critter.h"


class Bird : public Critter
{
private:
    int direction;
    int iteration;
    Direction Edirection;
public:
    Bird();
    virtual bool eat() override;
    virtual Attack fight(std::string opponent)override;
    virtual std::string getColor()override;
    virtual Direction getMove()override;
    virtual std::string getType() const override;
    virtual std::string toString()override;




};

#endif // ANT_H
