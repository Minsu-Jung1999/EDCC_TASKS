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
	printHelper(letter, 0, outputresults,0);
}

void Anagrams::print(string& phrase, int max)
{
	if (phrase.size() == 0) 
		return;
	if (max == 0)
		print(phrase);
	else
	{
		LetterInventory letter(phrase);
		vector <string> outputresults;
		printHelper(letter, 0, outputresults, max);
	}
	
}

void Anagrams::printHelper(LetterInventory& letters,int index, vector <string> results,int maxval)
{
	
	if (letters.isEmpty())
	{
		if (maxval != 0 && results.size()!= maxval)
		{
			return;
		}
		else
		{
			cout << "[";
			for (size_t i = 0; i < results.size(); i++)
			{
				cout << results[i];
				if (i + 1 < results.size())
					cout << ", ";
			}

			cout << "]" << endl;
			return;

		}
	}
	if (index + 1 > wordsInPhrase.size())
	{
		return;
	}
	if (letters.contains(wordsInPhrase[index])) // abash meet bar
	{
		results.push_back(wordsInPhrase[index]);
		LetterInventory chosen(wordsInPhrase[index]);
		LetterInventory leftletters = letters - chosen;
		printHelper(leftletters, 0, results,maxval);
		results.pop_back();
		printHelper(letters, index + 1, results,maxval);
		//cout << " Fisnish! " << endl;
		//cout << " current words in phrase " << wordsInPhrase[index] << endl;
		//cout << " current letters : " << letters << endl;
		//cout << " current index : " << index << endl;
	}
	else
	{
		printHelper(letters, index + 1, results,maxval);
	}

}

bool Anagrams::containVowels(LetterInventory& letters)
{
	return (letters.contains("a") || letters.contains("e") || letters.contains("i") || letters.contains("o") || letters.contains("u"));
}
