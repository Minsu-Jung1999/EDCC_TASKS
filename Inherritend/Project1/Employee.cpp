#include <iostream>
#include "Employee.h"
#include <string>
using namespace std;


Employee::Employee(string name, int years)
{
	myname = name;
	myyears = years;
}

int Employee::hours() {
	return 40;
}
string Employee::name()const {
	return myname;
}
double Employee::salary() const {
	return 40000.0 + (500 * myyears);
}
int Employee::vacationDays() {
	return 10;
}
string Employee::vacationForm() {
	return "yellow";
}
int Employee::years() {
	return myyears;
}