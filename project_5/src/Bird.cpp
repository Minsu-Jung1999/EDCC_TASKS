
#include "Bird.h"

Bird::Bird() {
    direction = 0;
    iteration = 0;
    Edirection = CENTER;
}
bool Bird::eat() {
    return false;
}
Attack Bird::fight(std::string opponent) {
    if(opponent == "%")
    {
        return ROAR;
    }
    else
    {
        return POUNCE;
    }
}
std::string Bird::getType() const {
    return "Bird";
}
std::string Bird::toString() {
    switch(Edirection)
    {
    case NORTH:
        return "^";
        break;
    case EAST:
        return ">";
        break;
    case SOUTH:
        return "V";
        break;
    case WEST:
        return "<";
        break;
    default:
        return "^";
        break;

    }
}
Direction Bird::getMove() {
    int currentDirection = direction/3;
    if(currentDirection == 4)
    {
        direction =0;
        currentDirection = 0;
    }
    switch(currentDirection)
    {
    case 0:
        Edirection = NORTH;
        break;
    case 1:
        Edirection = EAST;
        break;
    case 2:
        Edirection =  SOUTH;
        break;
    case 3:
        Edirection =  WEST;
        break;
    default:
        Edirection = CENTER;
        break;
    }

    direction++;
    return Edirection;

}
std::string Bird::getColor() {
    return "blue";
}
