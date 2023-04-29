/*
* Minsu Jung
* CS 132 Project 2
* April 22
*
* This is a CPP file for the implementation of the LetterInventory class, which represents the frequency of letters in a given string.
* It includes functions for setting the frequency of a specific letter, checking if the inventory contains a given string or LetterInventory object,
* and performing arithmetic operations between LetterInventory objects.
*
*/
#include "LetterInventory.h"
#include <iostream>
using namespace std;

// This function initializes the LetterInventory object by taking a string as input and
// counting the frequency of each letter in the string.
LetterInventory::LetterInventory(string data) :lettersize(0)
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

// This function sets the value of a specific letter in the LetterInventory object and
// updates the lettersize accordingly.
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

// This function returns the size of the LetterInventory object.
int LetterInventory::size()
{
	return lettersize;
}

// This function checks if the LetterInventory object is empty.
bool LetterInventory::isEmpty()
{
	return lettersize == 0;
}

// This function checks if the LetterInventory object contains all the letters in a given string.
bool LetterInventory::contains(string other)
{
	LetterInventory otherInv(other);
	return contains(otherInv);
}

// This function checks if the LetterInventory object contains all the letters in a given
// LetterInventory object.
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

// This function returns the frequency of a specific letter in the LetterInventory object.
int LetterInventory::operator[](char letter)
{
	int index = charToIndex(letter);
	if (!isalpha(letter))
	{
		throw string("Invalid argument");
	}
	return letterInventory[index];
}

// This function adds two LetterInventory objects and returns the sum.
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

// This function subtracts a LetterInventory object from another and returns the difference.
LetterInventory LetterInventory::operator-(const LetterInventory& otherInven) const
{
	LetterInventory diffInv("");
	for (int i = 0; i < 26; i++) {
		diffInv.letterInventory[i] = letterInventory[i] - otherInven.letterInventory[i];
		diffInv.lettersize += diffInv.letterInventory[i];
		if (diffInv.letterInventory[i] < 0) {
			throw std::string("Invalid argument");
		}
	}
	return diffInv;
}

// This function overloads the << operator to print the letters in the LetterInventory object in alphabetical order.
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
