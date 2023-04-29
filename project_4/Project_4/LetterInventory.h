/*
* Minsu Jung
* CS 132 Project 2
* April 22
*
* This file defines a C++ class called LetterInventory, which allows for the creation and manipulation of inventories
* of alphabetic letters within a string. It includes member functions for setting counts, checking if inventories contain specific letters
* or other inventories, and performing addition and subtraction operations between two inventories.
*
*/
#ifndef _LetterInventory_h_
#define _LetterInventory_h_

#include <iostream>
using namespace std;
class LetterInventory
{
private:
	char letter;
	int value;
	int lettersize;
	string lowerCaseWord;
	static const int ALPHABET_MAX = 26;
	int letterInventory[ALPHABET_MAX] = { 0, };
	// Helper function to convert a char to an index in the counts array
	int charToIndex(char alpha) const {
		return tolower(alpha) - 'a';
	}
public:
	// Constructs an inventory (a count) of the alphabetic letters in the given string,
	// ignoring the case of lettersand ignoring any non - alphabetic characters.
	LetterInventory(string data);

	// Sets the count for the given letter to the given value. letter might be lowercase
	// or uppercase.If a nonalphabetic character is passed or if value is negative, the
	// member function throw a string exception.
	void set(char letter, int value);

	// Returns the sum of all the counts in this inventory.
	int size();

	// Returns true if this inventory is empty (all counts are 0). This operation fast 
	// in that it does not need to examine each of the 26 counts when it is called
	bool isEmpty();

	// This function checks if the LetterInventory object contains all the letters in a given string.
	bool contains(string other);

	// This function checks if the LetterInventory object contains all the letters in a given LetterInventory.
	bool contains(LetterInventory other);

	// Returns a count of how many of this letter are in the inventory. letter might be lowercase or uppercase
	// (the member function shouldn¡¯t care). If a nonalphabetic character is passed, the member function 
	// throw a string exception.
	int operator[] (char letter);

	// Outputs a string representation of the inventory with the letters all in lowercase and in sorted order and
	// surrounded by square brackets. The number of occurrences of each letter match its count in the inventory.
	friend ostream& operator<<(ostream& out, const LetterInventory& otherInven);

	// Constructs and returns a new LetterInventory object that represents the sum of this LetterInventory
	// and the other given LetterInventory.The counts for each letter should be added together.The two
	// LetterInventory objects being added together(this and other) will not be changed by this operator.
	LetterInventory operator+(const LetterInventory& otherInven) const;

	// Constructs and returns a new LetterInventory object that represents the result of subtracting the other
	// inventory from this inventory(i.e., subtracting the counts in the other inventory from this object¡¯s counts).If
	// any resulting count would be negative, the  member function throw a string exception.The two
	// LetterInventory objects being subtracted(thisand other) will not be changed by this operator
	LetterInventory operator-(const LetterInventory& otherInven) const;


};


#endif
