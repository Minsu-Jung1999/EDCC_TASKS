
#include "Cat.h"
#include <random>
Cat::Cat() {
    randomDirection = 0;
    randomMoveAmount = 0;
}
bool Cat::eat() {
    return true;
}
std::string Cat::getType() const {
    return "Cat";
}

Attack Cat::fight(std::string opponent) {
    int choice = rand() % 3; // 0 ~ 2
    switch(choice)
    {
    case 0:
        return POUNCE;
        break;
    case 1:
        return ROAR;
        break;
    default:
        return SCRATCH;
        break;
    }
}
std::string Cat::toString() {

    switch(E_State)
    {
    case 0:
        return "@";
        break;
    case 1:
        return "z";
        break;
    case 2:
        return "!";
        break;
    case 3:
        return "W";
        break;
    case 4:
        return "_";
        break;
    default:
        return "@";
        break;

    }
}
Direction Cat::getMove() {
    if(randomMoveAmount == 0)
    {
        randomDirection = rand() % 4; // 0 ~ 3
        randomMoveAmount  = rand() % MAXAMOUNT + 1; // 1 ~ MAXAMOUNT+1(11)
    }
    randomMoveAmount--;
    switch(randomDirection)
    {
    case 0:
        return NORTH;
        break;
    case 1:
        return EAST;
        break;
    case 2:
        return SOUTH;
        break;
    case 3:
        return WEST;
        break;
    default:
        return CENTER;
        break;
    }

}
std::string Cat::getColor() {
    switch(E_State)
    {
    case 0:
        return "orange";
        break;
    case 1:
        return "green";
        break;
    case 2:
        return "red";
        break;
    case 3:
        return "blue";
        break;
    case 4:
        return "red";
        break;
    default:
        return "orange";
        break;

    }
}

void Cat::onLose()
{
    E_State = LOSE;
}
void Cat::onMate()
{
    E_State = MATE;
}
void Cat::onMateEnd()
{
    E_State = DEFAULT;
}
void Cat::onSleep()
{
    E_State = SLEEP;
}
void Cat::onWakeUp()
{
    E_State = DEFAULT;
}
void Cat::onWin()
{
    E_State = WIN;
}
