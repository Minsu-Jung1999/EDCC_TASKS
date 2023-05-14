
#include "Cougar.h"

Cougar::Cougar() {
    west = true;
    fought = false;
}
bool Cougar::eat() {
    west = !west;
    return true;
}
Attack Cougar::fight(std::string opponent) {
    fought = true;
    return POUNCE;
}
std::string Cougar::getType() const {
    return "Cougar";
}
std::string Cougar::toString() {
    return "C";
}
Direction Cougar::getMove() {
   return west ? WEST : EAST;
}
std::string Cougar::getColor() {
   return fought ? "red" : "blue";
}
