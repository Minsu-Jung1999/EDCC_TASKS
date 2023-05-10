#include "Lawyer.h"
#include <iostream>
#include <string>
using namespace std;

Lawyer::Lawyer(string name, int years, string lawSchool): Employee(name, years) {
	mylawSchool = lawSchool;
}
double Lawyer::salary() const {
	return Employee::salary() * 2;
}
void Lawyer::sue(string person) {
	cout << person << ", I'll see you in court!" << endl;
}
string Lawyer::name() const {
	return Employee::name() + ", Esq.";
}