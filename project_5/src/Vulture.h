
#ifndef VULTURE_H
#define VULTURE_H

#include "Bird.h"


class Vulture : public Bird
{
private:
    bool hungry;
public:
    Vulture();
    virtual bool eat() override;
    virtual Attack fight(std::string opponent)override;
    virtual std::string getColor()override;
    virtual std::string getType() const override;

};

#endif // VULTURE_H
