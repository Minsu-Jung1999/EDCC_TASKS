// replace this comment with your AnagramSolver cpp code

#include "AnagramSolver.h"
#include "LetterInventory.h"
#include <vector>
#include <iostream>	

using namespace std;

Anagrams::Anagrams(vector<string>& dictionary):dictionary(dictionary)
{
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
	vector <string> outputresults;
	printHelper(letter, 0, outputresults);

}

void Anagrams::print(string& phrase, int max)
{
	if (phrase.size() == 0) 
		return;
	if (max == 0)
		print(phrase);
}

bool Anagrams::printHelper(LetterInventory& letters,int index, vector <string>& results)
{
	if (!containVowels(letters))
		return false;
	if (letters.isEmpty()) // success
	{
		cout << '[';
		for (int i = 0; i < results.size(); i++)
		{
			cout << results[i];
			if (i + 1 < results.size())
				cout << ", ";
		}
		cout << ']' << endl;
		return true;
	}
	else if (index >= wordsInPhrase.size())
	{
		return false;
	}
	else if (letters.contains(wordsInPhrase[index]))
	{
		results.push_back(wordsInPhrase[index]);
		LetterInventory chosen(wordsInPhrase[index]);
		LetterInventory left = letters - chosen;
		if (printHelper(left, index + 1, results))
		{
		}
		else
		{
			results.pop_back();
			return printHelper(letters, index + 1, results);
		}
	}
	return printHelper(letters, index + 1, results);

}

bool Anagrams::containVowels(LetterInventory& letters)
{
	return (letters.contains("a") || letters.contains("e") || letters.contains("i") || letters.contains("o") || letters.contains("u"));
}
