#include <iostream>
#include <vector>
#include "lib132.h"
using namespace std;


int main()
{
	vector <string> v = { "to", "be", "or", "not", "to", "be", "hamlet" };
	removeEvenLength(v);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

