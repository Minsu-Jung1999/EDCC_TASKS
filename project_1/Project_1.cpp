#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>
#include "Project_1.h"
using namespace std;

bool FindingFile(std::string input_file_name_)
{
	ifstream file(input_file_name_);
	if (file.good())
	{
		return true;
	}
	else
	{
		cout << "File not Found. Try again: ";
		return false;
	}
	file.close();
}

void GameStartText()
{
	cout << "Welcome to the game of Mad Libs." << endl;
	cout << "I will ask you to provide several words" << endl;
	cout << "and phrases to fill in a mad lib story." << endl;
	cout << "The result will be written to an output file." << endl <<endl;
}

int ModeSetting()
{
	string userInput;
	while (true)
	{
		cout << "Create, view or quit? ";
		cin >> userInput;
		string input_to_lower = string(userInput.length(), '\0');							// need to match the length of the two strings
		transform(userInput.cbegin(), userInput.cend(), input_to_lower.begin(), tolower);	// change upper case to lower case.
		
		if (input_to_lower.compare("create")==0)
		{
			return EMode::CREATE_MODE;
		}
		else if (input_to_lower.compare("view")==0)
		{
			return EMode::VIEW_MODE;
		}
		else if (input_to_lower.compare("quit")==0)
		{
			exit(0);
		}

	}
}

void CreateFile()
{
	string input_file_name;
	string output_file_name;
	bool bfind = false;
	cout << "Input File Name: ";
	while (!bfind)
	{
		cin >> input_file_name;
		bfind = FindingFile(input_file_name);
	}
	// Readmode file
	ifstream Read_File(input_file_name);
	string file_contents;
	file_contents.assign((std::istreambuf_iterator<char>(Read_File)), std::istreambuf_iterator<char>());

	AskingQuestions(file_contents);  // 파일 내용 문자열을 매개변수로 전달

	// Write mode file
	cout << "Output file name: ";
	cin >> output_file_name;
	ofstream Write_File(output_file_name);

	Read_File.close();
}

void ViewFile()
{

}

void AskingQuestions(string file_contents)
{
	cout << "AskingQuestions ()" << endl;
	vector<string> words;
	vector<string> replaced_words;
	int start = 0, count = 0;
	string content = file_contents;
	cout << "content = "<<content << endl;
	int words_count=0;
	for (int i = 0; i < file_contents.size(); i++)
	{
		if (file_contents[i] == '<')
		{
			start = i+1;
			while (file_contents[++i] != '>')
			{
				count++;
			}
			words.push_back(file_contents.substr(start, count));	// Extract specific words and assgin into string vector
			count = 0;
		}
	}

	// Questioning
	for (int i = 0; i < words.size(); i++)
	{
		string user_input;
		string temp_word = words[i];
		cout << "Please type ";
		if (temp_word[0] == 'a')
			cout << "an ";
		else
			cout << "a ";
		cout << temp_word << ": ";
		cin >> user_input;
		replaced_words.push_back(user_input);
	}

	// replacing


}

string Replace(string replaced_words)
{
	string words;

	return words;
}
