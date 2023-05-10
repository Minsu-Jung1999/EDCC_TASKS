#ifndef _lawyer_h
#define _lawyer_h
#include <string>
#include "Employee.h"	
using namespace std;

class Lawyer : public Employee {
public:
	Lawyer(string name, int years, string lawSchool);
	virtual double salary() const override;
	//virtual void sue(string person)override;
	virtual string name() const override;
private:
	string mylawSchool;
};
#endif