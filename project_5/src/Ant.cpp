
#include "Ant.h"

Ant::Ant(bool walkSouth) {
    this->walkSouth = walkSouth;
    changeDirection =false;
}
bool Ant::eat() {
    return true;
}
Attack Ant::fight(std::string opponent) {
    return SCRATCH;
}
std::string Ant::getType() const {
    return "Ant";
}
std::string Ant::toString() {
    return "%";
}
Direction Ant::getMove() {

    changeDirection = !changeDirection;
    if(walkSouth)   // S - E - S - E .....
    {
        return changeDirection ? SOUTH : EAST;
    }
    else // N - E - N - E .....
    {
        return changeDirection ? NORTH : EAST;
    }

}
std::string Ant::getColor() {
    return "red";
}
