
#include "Vulture.h"

Vulture::Vulture() {
    hungry = true;
}
bool Vulture::eat() {
    if(!hungry)
    {
        return false;
    }
    else
    {
        hungry =false;
        return true;
    }
}
Attack Vulture::fight(std::string opponent) {
    if(!hungry)
    {
        hungry = true;
    }
    if(opponent == "%")
    {
        return ROAR;
    }
    else
    {
        return POUNCE;
    }
}
std::string Vulture::getType() const {
    return "Vulture";
}


std::string Vulture::getColor() {
    return "black";
}
