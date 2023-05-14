
#ifndef HIPPO_H
#define HIPPO_H

#include "Critter.h"


class Hippo : public Critter
{
private:
    bool fullness;
    int randomDirection;
    int moveAmount;
    int hungerTimes;
public:
    Hippo(int hunger);
    virtual bool eat() override;
    virtual Attack fight(std::string opponent)override;
    virtual std::string getColor()override;
    virtual Direction getMove()override;
    virtual std::string getType() const override;
    virtual std::string toString()override;




};

#endif // ANT_H
