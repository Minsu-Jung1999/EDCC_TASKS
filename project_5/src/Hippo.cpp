
#include "Hippo.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
Hippo::Hippo(int hunger) {
    fullness = false;
    if(hunger == 0)
    {
        fullness = true;
    }
    randomDirection=0;
    moveAmount=0;
    hungerTimes = hunger;
}
bool Hippo::eat() {

    if(hungerTimes==0)
    {
        fullness = true;
    }
    else
    {
        hungerTimes--;
    }
    return !fullness;
}
Attack Hippo::fight(std::string opponent) {
    if(fullness=false) // Hungry
    {
        return SCRATCH;
    }
    else
    {
        return POUNCE;
    }
}
std::string Hippo::getType() const {
    return "Hippo";
}
std::string Hippo::toString() {
    return std::to_string(hungerTimes);
}
Direction Hippo::getMove() {
    srand(time(0)); // using current time for seed;

    if(moveAmount==0 || moveAmount == 5)
    {
        randomDirection = rand() % 4; // 0 ~ 3
        moveAmount = 0;
    }
    moveAmount++;
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
std::string Hippo::getColor() {
    return hungerTimes==0 ? "white" : "gray";
}
