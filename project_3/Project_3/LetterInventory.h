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
	LetterInventory(string data);

	void set(char letter, int value);

	int size();

	bool isEmpty();

	bool contains(string other);

	bool contains(LetterInventory other);
	int operator[] (char letter);
	friend ostream& operator<<(ostream& out, const LetterInventory& otherInven);
	LetterInventory operator+(const LetterInventory& otherInven) const;
	LetterInventory operator-(const LetterInventory& otherInven) const;


	// temper
	void printword();
};


#endif
