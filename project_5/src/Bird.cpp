/*
 *
 * Minsu Jung
 * CS 132 Project 2
 * May 14
 *
 * This code defines the behavior and attributes of a bird object in a simple simulation.
 *
*/
#include "Bird.h"


// Initialize member variables.
Bird::Bird()
{
    direction = 0;
    iteration = 0;
    Edirection = CENTER;
}

// never eats (always returns false)
bool Bird::eat()
{
    return false;
}
// roars if the opponent looks like an Ant ("%"); otherwise pounces
Attack Bird::fight(std::string opponent)
{
    if(opponent == "%")
    {
        return ROAR;
    }
    else
    {
        return POUNCE;
    }
}

// its name.
std::string Bird::getType() const
{
    return "Bird";
}
// indicate the direction that the bird object is moving.
std::string Bird::toString()
{
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
// A clockwise square: first goes north 3 times, then east 3 times,
// then south 3 times, then west 3 times, then repeats
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

// always blue.
std::string Bird::getColor() {
    return "blue";
}
