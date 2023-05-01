#ifndef ANAGRAMSOLVER_H
#define ANAGRAMSOLVER_H

#include <iostream>
#include <vector>
#include "LetterInventory.h"
class Anagrams
{
private:
	vector<string> dictionary;
	vector<string> wordsInPhrase;
	vector<string> anagrams;
public:
	Anagrams(vector<string>& dictionary);
	vector<string> getWords(string& phrase);
	void print(string& phrase);
	void print(string& phrase, int max);
	
	// additional funcitons
	void printHelper(LetterInventory& letters, int index, vector <string> results, int maxval);
	bool containVowels(LetterInventory& phrase);
};

#endif // HEADER_FILE_NAME_H
