#include "LetterInventory.h"
#include "lib132.h"
#include <iostream>
using namespace std;

LetterInventory::LetterInventory(string data):lettersize(0)
{
	for (char alpha : data) 
	{
		if (isalpha(alpha)) 
		{
			letterInventory[charToIndex(alpha)]++;
			lettersize++;
		}
	}
}

void LetterInventory::set(char letter, int value)
{
	int index = charToIndex(letter);
	if (!isalpha(letter) || value < 0) 
	{
		throw std::invalid_argument("Invalid argument");
	}
	lettersize += value - letterInventory[index];
	letterInventory[index] = value;
}

int LetterInventory::size()
{
	return lettersize;
}

bool LetterInventory::isEmpty()
{
	return lettersize == 0;
}

bool LetterInventory::contains(string other)
{
	LetterInventory otherInv(other);
	return contains(otherInv);
}

bool LetterInventory::contains(LetterInventory other)
{
	for (int i = 0; i < 26; i++) 
	{
		if (letterInventory[i] < other.letterInventory[i]) 
		{
			return false;
		}
	}
	return true;
}

int LetterInventory::operator[](char letter)
{
	int index = charToIndex(letter);
	if (!isalpha(letter))
	{
		throw string("Invalid argument");
	}
	return letterInventory[index];
}

LetterInventory LetterInventory::operator+(const LetterInventory& otherInven) const
{
	LetterInventory sumInv("");
	for (int i = 0; i < 26; i++)
	{
		sumInv.letterInventory[i] = letterInventory[i] + otherInven.letterInventory[i];
		sumInv.lettersize += sumInv.letterInventory[i];
	}
	return sumInv;
}

LetterInventory LetterInventory::operator-(const LetterInventory& otherInven) const
{
	LetterInventory diffInv("");
	for (int i = 0; i < 26; i++) {
		diffInv.letterInventory[i] = letterInventory[i] - otherInven.letterInventory[i];
		diffInv.lettersize += diffInv.letterInventory[i];
		if (diffInv.letterInventory[i] < 0) {
			throw std::invalid_argument("Invalid argument");
		}
	}
	return diffInv;
}

void LetterInventory::printword()
{
	cout << lowerCaseWord;
	cout << endl;
	for (size_t i = 0; i < 26; i++)
	{
		cout << letterInventory[i] << ", ";
	}
}

ostream& operator<<(ostream& out, const LetterInventory& otherInven)
{
	out << "[";
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < otherInven.letterInventory[i]; j++)
		{
			out << (char)('a' + i);
		}
	}
	out << "]";
	return out;
}
