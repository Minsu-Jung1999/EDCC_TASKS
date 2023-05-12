/*
* Minsu Jung
* CS 132 Project 2
* April 29
*
* This cpp file defines the Anagrams class with a constructor that takes a vector called dictionary as a parameter. 
* It also includes the LetterInventory and AnagramSolver headers, as well as the <vector> and <iostream> headers. 
* This cpp file provides functions to get words from a given phrase and print the results based on certain conditions.
*/

#include "AnagramSolver.h"
#include "LetterInventory.h"
#include <vector>
#include <iostream>	

using namespace std;

// Constructor for the Anagrams class that initializes the dictionary member variable with the provided vector.
Anagrams::Anagrams(vector<string>& dictionary):dictionary(dictionary){}

// Retrieves words from the given phrase by comparing it with the words in the dictionary and returns a vector of matching words.
vector<string> Anagrams::getWords(string& phrase)
{
	if (!(this->wordsInPhrase.empty()))	// it will activate after a user input a second anagram.
	{
		wordsInPhrase.clear();
	}
	LetterInventory letterInv(phrase);
	for (size_t i = 0; i < dictionary.size(); i++)
	{
		if (letterInv.contains(dictionary[i]))
		{
			wordsInPhrase.push_back(dictionary[i]);
		}
	}

	return wordsInPhrase;
}

// Prints all possible anagrams of the phrase by recursively calling the printHelper function with appropriate parameters.
const void Anagrams::print(string& phrase)
{
	LetterInventory letter(phrase);
	vector <string> outputresults;
	int index=0;
	int maxLevel=0;
	printHelper(letter, index, outputresults,maxLevel);
}

// Prints anagrams of the phrase up to a maximum length of max, or all anagrams if max is 0. 
// Uses the printHelper function to perform the recursive printing.
// phrase is string from a user's input, max is amount of anagrams.
const void Anagrams::print(string& phrase, const int max)
{
	if (phrase.size() == 0) 
		return;
	if (max == 0)
		print(phrase);
	else
	{
		LetterInventory letter(phrase);
		vector <string> outputresults;
		int index=0;
		printHelper(letter, index, outputresults, max);
	}
}

// Helper function to print words in the given results vector with comma-separated formatting.
const void Anagrams::printWords(const vector<string>& results)
{
	if (results.empty())
	{
		return;
	}
	cout << results.front();
	if (results.size() > 1)
	{
		cout << ", ";
	}
	printWords(std::vector<string>(results.begin() + 1, results.end()));
}

// Recursive helper function that generates and prints anagrams based on the provided letters (remaining letters), current index, and previous results.
// It considers the maximum length of anagrams as maxval.
// maxval reffers amount of anagrams for printing.
const void Anagrams::printHelper(LetterInventory& letters,int index, vector <string> results, const int maxval)
{
	if (results.size() > maxval)
	{
		return;
	}
	// completed case
	if (letters.isEmpty())
	{
		if (maxval != 0 && results.size()!= maxval)
		{
			return;
		}
		else
		{
			cout << "[";
			printWords(results);
			cout << "]" << endl;
			return;
		}
	}
	else if (index + 1 > wordsInPhrase.size())	// to avoid out of range
	{
		return;
	}
	else if (letters.contains(wordsInPhrase[index])) // anagram case
	{
		results.push_back(wordsInPhrase[index]);
		LetterInventory chosen(wordsInPhrase[index]);	// chosen word's alphabet
		LetterInventory leftletters = letters - chosen;	// left word's alphabet
		printHelper(leftletters, 0, results,maxval);
		results.pop_back();
		printHelper(letters, index + 1, results,maxval);	// Back Tracking (Finding all possible anagram matching)
	}
	else
	{
		printHelper(letters, index + 1, results,maxval);
	}
}

