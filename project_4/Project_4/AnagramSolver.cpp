// replace this comment with your AnagramSolver cpp code

#include "AnagramSolver.h"
#include "LetterInventory.h"
#include <vector>
#include <iostream>	

using namespace std;

Anagrams::Anagrams(vector<string>& dictionary)
{
	
	this->dictionary = dictionary;
}

vector<string> Anagrams::getWords(string& phrase)
{
	if (!(this->wordsInPhrase.empty()))
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

void Anagrams::print(string& phrase)
{
	LetterInventory letter(phrase);
	int index = 0;
	for (size_t i = 0; i < wordsInPhrase.size(); i++)
	{
		if (printHelper(letter, i))
		{
		}
	}
}

void Anagrams::print(string& phrase, int max)
{
	if (phrase.size() == 0) 
		return;
	if (max == 0)
		print(phrase);
}

bool Anagrams::printHelper(LetterInventory& letters,int index)
{
	if (containVowels(letters))
	{
		LetterInventory chosen(wordsInPhrase[index]);
		if (letters.contains(chosen))
		{
			LetterInventory leftletters = letters - chosen;
			printHelper(leftletters, index + 1);
		}
	}
	else
		return false;
}

bool Anagrams::containVowels(LetterInventory& letters)
{
	return (letters.contains("a") || letters.contains("e") || letters.contains("i") || letters.contains("o") || letters.contains("u"));
}
