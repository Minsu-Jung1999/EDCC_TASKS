
#ifndef COUGAR_H
#define COUGAR_H

#include "Critter.h"


class Cougar : public Critter
{
private:
    bool west;
    bool fought;
public:
    Cougar();
    virtual bool eat() override;
    virtual Attack fight(std::string opponent)override;
    virtual std::string getColor()override;
    virtual Direction getMove()override;
    virtual std::string getType() const override;
    virtual std::string toString()override;



};

#endif // COUGAR_H
