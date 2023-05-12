/*
* Minsu Jung
* CS 132 Project 2
* April 29
*
* The code defines the Anagrams class with a constructor that takes a dictionary, 
* and provides functions to get words from a phrase, print anagrams, and check if a phrase contains vowels. 
* It includes the necessary headers and uses the LetterInventory class.
* 
*/
#ifndef ANAGRAMSOLVER_H
#define ANAGRAMSOLVER_H

#include <iostream>
#include <vector>
#include "LetterInventory.h"


class Anagrams
{
private:
	/** contains Anagrams from a file. */
	const vector<string> dictionary;	
	
	/** contains all anagrams from user's input */
	vector<string> wordsInPhrase;
	
public:
	/** Constructor that initializes the Anagrams object with the provided dictionary vector. */
	Anagrams(vector<string>& dictionary);
	
	/** Returns a vector of words from the dictionary that can be formed using the letters in the given phrase. */
	vector<string> getWords(string& phrase);

	/** Prints all the anagrams of the phrase using the words from the dictionary. */
	const void print(string& phrase);

	/**Prints anagrams of the phrase up to a maximum length of max, or all anagrams if max is 0. */
	const void print(string& phrase, const int max);
	
	/** Helper function that recursively generates and prints anagrams based on the remaining letters, 
	/**	current index, previous results, and the maximum length of anagrams specified by maxval. */
	const void printHelper(LetterInventory& letters, int index, vector <string> results, const int maxval);

	/** Function added for printing recursively. */
	const void printWords(const vector<string>& results);
};

#endif // HEADER_FILE_NAME_H
