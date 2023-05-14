#ifndef CAT_H
#define CAT_H

#include "Critter.h"


class Cat: public Critter
{
private:
    enum State {
        DEFAULT=0,
        SLEEP,
        MATE,
        WIN,
        LOSE,
        WAKEUP
    } E_State;
    bool sparkSleep;
    bool sparkMate;
    bool sparkWin;
    bool sparkLose;
    int winStayTime;
    int randomDirection;
    int randomMoveAmount ;
    const int MAXAMOUNT = 10;
public:
    Cat();
    virtual bool eat() override;
    virtual Attack fight(std::string opponent)override;
    virtual std::string getColor()override;
    virtual Direction getMove()override;
    virtual std::string getType() const override;
    virtual std::string toString()override;

    virtual void onLose()override;
    virtual void onMate()override;
    virtual void onMateEnd()override;
    virtual void onSleep()override;
    virtual void onWakeUp()override;
    virtual void onWin()override;
    std::string Sparkling(std::string first, std::string second);

};

#endif // ANT_H
