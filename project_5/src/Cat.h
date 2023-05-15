// This is the header file for the Cat class, a derived class of Critter.
// Cat class simulates a Cat in a game or simulation.


#ifndef CAT_H
#define CAT_H


#include "Critter.h"


class Cat: public Critter
{
private:
    enum State { // Enumeration for different states of Cat.
        DEFAULT=0, // Default state.
        SLEEP, // Sleeping state.
        MATE, // Mating state.
        WIN, // Winning state.
        LOSE, // Losing state.
        WAKEUP // Waking up state.
    } E_State;
    int randomDirection; // Indicates the randomly-chosen direction of the Cat's move.
    int randomMoveAmount ; // Indicates the randomly-chosen amount of movement.
    const int MAXAMOUNT = 10; // The maximum amount of movement in a single move.


public:
    Cat(); // Constructor that initializes State, spark flags and random variables.
    virtual bool eat() override; // Determines whether the Cat ate and returns the result.
    virtual Attack fight(std::string opponent) override; // Determines the Cat's attack against an opponent.
    virtual std::string getColor() override; // Returns the color of the Cat as a string ("pink").
    virtual Direction getMove() override; // Determines the direction of the Cat's move.
    virtual std::string getType() const override; // Returns the type of the Cat as a string ("Cat").
    virtual std::string toString() override; // Returns a string representation of the Cat.


    // The following are the special state-changing functions implemented for the Cat class.
    virtual void onLose() override;
    virtual void onMate() override;
    virtual void onMateEnd() override;
    virtual void onSleep() override;
    virtual void onWakeUp() override;
    virtual void onWin() override;

};


#endif // CAT_H
