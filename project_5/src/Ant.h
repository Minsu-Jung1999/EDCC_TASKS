
#ifndef ANT_H
#define ANT_H

#include "Critter.h"


class Ant : public Critter
{
private:
    bool walkSouth;
    bool changeDirection;
public:
    Ant(bool walkSouth);
    virtual bool eat() override;
    virtual Attack fight(std::string opponent)override;
    virtual std::string getColor()override;
    virtual Direction getMove()override;
    virtual std::string getType() const override;
    virtual std::string toString()override;




};

#endif // ANT_H
