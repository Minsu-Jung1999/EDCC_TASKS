#include "Animal.h"
#include <iostream>
using namespace std;
Animal::Animal()
{
	cout << "Parent Animal() called" << endl;
}

void Animal::barks()
{
	cout << "Animal's barks() Called" << endl;
}
