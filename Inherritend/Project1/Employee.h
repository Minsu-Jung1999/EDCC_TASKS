#ifndef _employee_h
#define _employee_h
#include <iostream>
#include <string>

class Employee {
public:
	Employee(string name,int years);
	virtual int hours();
	virtual string name() const;
	virtual double salary() const;
	virtual int vacationDays();
	virtual string vacationForm();
	virtual int years();
private:
	string myname;
	int myyears;
};

#endif