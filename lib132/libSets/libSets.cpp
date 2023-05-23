#include <iostream>
#include <vector>
#include <fstream>
#include "lib132.h"
using namespace std;

#pragma region MidtermFunctions

void conFlip(string FileName)
{
	ifstream File;
	File.open(FileName);
	char a;
	int headcounter = 0;
	int tailcounter = 0;
	int total = 0;
	while (File >> a)
	{
		if (tolower(a) == 't')
		{
			tailcounter++;
			total++;
		}
		else if (tolower(a) == 'h')
		{
			headcounter++;
			total++;
		}
	}
	int result = (double)headcounter / total * 100;
	cout << headcounter << " heads" << " (" << result << ")" << endl;
	if (result >= 50)
		cout << "You win!";
	else
		cout << "You lose!";
	
}

void printstaris1(vector<int> n)
{
	if (n.empty())
		return;
	cout << n.front();
	if (n.size() - 1 > 0)
		cout << ", ";
	return printstaris1(vector<int>(n.begin() + 1, n.end()));
}



void waysToClimbHelper1(int stairs, vector<int>& path)
{
	if (stairs == 0)
	{
		cout << "{";
		printstaris1(path); 
		cout << "}";
		cout << endl;

	}
	if (stairs >= 1)
	{
		path.push_back(1);
		waysToClimbHelper1(stairs - 1, path);
		path.pop_back();
	}
	if (stairs >= 2)
	{
		path.push_back(2);
		waysToClimbHelper1(stairs - 2, path);
		path.pop_back();
	}
}
// ways to climb ³ª¿Ãµí?
void waysToClimb1(int stairs)
{
	if (stairs < 0)
	{
		
		return;
	}
	else
	{
		vector<int> path;
		waysToClimbHelper1(stairs, path);
	}
}
#pragma endregion

void stretch23(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % 2 == 0) // 2345
		{
			int data = v[i];
			v.erase(v.begin() + i, v.begin()+i + 1); // 345
			v.insert(v.begin() + i, data / 2); // 1345
			v.insert(v.begin() + i+1, data / 2); // 11345 i = 0
		}
		else
		{
			int data = v[i];
			v.erase(v.begin() + i, v.begin()+i + 1); // 345
			v.insert(v.begin() + i, data / 2+1); // 1345
			v.insert(v.begin() + i+1, (data / 2)); // 1345
		}
		i++;
	}
}
#pragma region polymorphism
class Vegetable {
public:
	virtual void two() {
		cout << "V 2" << endl;
	}
};
class Mineral : public Vegetable {
public:
	virtual void one() {
		cout << "M 1" << endl;
	}

	virtual void two() {
		cout << "M 2" << endl;
	}
};
class Animal : public Mineral {
public:
	virtual void one() {
		cout << "A 1" << endl;
		two();
	}
	virtual void three() {
		cout << "A 3" << endl;
	}
};
class Computer : public Animal {
public:
	virtual void two() {
		cout << "C 2" << endl;
		Mineral::two();
	}

		virtual void three() {
		cout << "C 3" << endl;
	}
};
#pragma endregion


int main()
{
	Vegetable* var1 = new Computer();
	Mineral* var2 = new Animal();
	Vegetable* var3 = new Vegetable();
	Animal* var4 = new Computer();
	((Animal*)var2)->one();
}

