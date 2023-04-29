#ifndef ANAGRAMSOLVER_H
#define ANAGRAMSOLVER_H

#include <iostream>
#include <vector>
using namespace std;

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
	bool printHelper(LetterInventory& letters);
	bool containVowels(LetterInventory& phrase);
};

#endif // HEADER_FILE_NAME_H
