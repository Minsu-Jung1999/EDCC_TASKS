#include <iostream>
#include <fstream>
#include <string>
#include "MadLibs.h"

// This function checks if a file exists and returns a boolean value based on its availability.
bool FileCheck(std::string fileName)
{
	std::ifstream file(fileName);

	if (file.good())
	{
		file.close();
		return true;
	}
	else
	{
		std::cout << "File not found. Try again: ";
		return false;
	}
}

// This function sets the mode of the game and returns the appropriate value stored in ENUM according to the user input.
int GameModeSetting(std::string userInput)
{
	while (true)
	{
		if (EqualsIgnoringCase("create",userInput))
		{
			return EMode::CREATEMODE;
		}
		else if (EqualsIgnoringCase("view", userInput))
		{
			return EMode::VIEWMODE;
		}
		else if (EqualsIgnoringCase("quit", userInput))
		{
			return EMode::QUIT;
		}
		return EMode::RETYPING;
	}
}

// This function allows users to create a mad-lib story by reading from an input file 
// and prompting them to fill in the placeholders.
void CreateMode()
{
	int startIndex = 0;		// index of " < "
	int endIndex = 0;		// index of " > "

	std::string inputFileName;	
	std::string outputFileName;
	std::string fileContents;		// store the strings from the file
	std::string fileReader;			// Read the line from the file
	//std::string placeHolder;		// hold the word inside of " < >  "
	
	std::cout << "Input file name: ";
	std::getline(std::cin,inputFileName);

	while (!FileCheck(inputFileName))
	{
		std::getline(std::cin, inputFileName);
	}

	if (FileCheck(inputFileName))
	{
		std::cout << "Output file name: ";
		std::getline(std::cin,outputFileName);
		std::cout << std::endl;
		//kstd::cin.ignore();	// ReplaceString has getline() so it needs.
	}	 

	std::fstream InputFile(inputFileName); // Create input file
	
	
	while (std::getline(InputFile, fileReader)) // store the words in the file to fileContents
		fileContents += fileReader + '\n';

	FindingPlaceHolder(fileContents,outputFileName);

	InputFile.close();

}
// This function finds the placeholders in the input file 
// and prompts the user to fill them in with their own words or phrases.
void FindingPlaceHolder(std::string fileContents, std::string outputFileName)
{
	std::string oldString;		
	std::string replacedword;	// store replaced word from
	char startTag = '<';
	char endTag = '>';
	int startPos = 0;
	while ((startPos = fileContents.find(startTag, startPos))!= std::string::npos)
	{
		int endPos = fileContents.find(endTag, startPos);
		if (endPos == std::string::npos)
			break;

		oldString = fileContents.substr(startPos+1, endPos - startPos -1);
		replacedword = ReplaceString(oldString);
		fileContents.replace(startPos, endPos - startPos + 1, replacedword);
		startPos += replacedword.length();
	}
	std::cout << "Your mad-lib story has been created!" << std::endl;
	std::cout << std::endl;
	WriteStory(fileContents,outputFileName);
}

// This function prompts the user to input a word or phrase to replace a placeholder in the mad-lib story.
std::string ReplaceString(std::string oldString)
{
	std::string newString;
	std::cout << "Please type ";
	
	if (oldString[0] == 'a')
	{
		std::cout << "an ";
	}
	else
	{
		std::cout << "a ";
	}

	std::cout << oldString << ": ";
	std::getline(std::cin, newString);
	return newString;
}

// This function writes the completed mad-lib story to an output file.
void WriteStory(std::string fileContents, std::string outputFileName)
{
	std::ofstream outFile(outputFileName);
	outFile<< fileContents;
	outFile.close();
}

// This function allows users to view a previously created mad-lib story according to user's inputfilename.
void ViewMode()
{
	std::string inputFileName;
	std::cout << "Input file name: ";
	std::getline(std::cin,inputFileName);

	while (!FileCheck(inputFileName))
	{
		std::getline(std::cin, inputFileName);
	}
	std::cout << std::endl;

	std::ifstream inputFile(inputFileName);
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
	}
	std::cout << std::endl;
	inputFile.close();
}

// This function checks if two strings are equal, ignoring their cases.
bool EqualsIgnoringCase(std::string compareWord, std::string userInput)
{
	if (compareWord.size() != userInput.size())return false;
	for (int i = 0; i < compareWord.size(); i++)
	{
		if (tolower(compareWord[i]) != tolower(userInput[i]))return false;
	}
	return true;
}

// This function displays a welcome message to the user at the beginning of the game.
void GameStartNotification()
{
	std::cout << "Welcome to the game of Mad Libs." << std::endl;
	std::cout << "I will ask you to provide several words" << std::endl;
	std::cout << "and phrases to fill in a mad lib story." << std::endl;
	std::cout << "The result will be written to an output file." << std::endl << std::endl;

}
