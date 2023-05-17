// Allison Obourn
// CS 132, Spring 2023
// Lecture 15

// This class represents an employee at a company
// Every employee has a name and number of years employed.

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
public:
    // creates an employee with the passed in name and number of years worked
    Employee(string name, int years);

    // returns the numberof hours the employee works per week
    virtual int hours();

    // returns the employee's name
    virtual string name();

    // Returns the employee's yearly salary. This is a base of 40000 with 
    // an additional 500 for every year worked
    virtual double salary();

    // returns the number of vacation days the employee gets per year. 
    virtual int vacationDays();

    // returns the color of the form the employee must use to apply to use
    // their vacation days
    virtual string vacationForm();

    // returns the number of years the employee has worked at the company
    virtual int years();

private:
    string myName; // employee's name
    int myYears;   // number of years employee has been at the company
};

#endif