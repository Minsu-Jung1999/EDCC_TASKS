#ifndef ADD_H
#define ADD_H

// Enumeration for different game modes
enum EMode
{
	CREATEMODE = 1,		// Mode for creating a story
	VIEWMODE,			// Mode for viewing an existing story
	QUIT,				// Mode for quitting the program
	RETYPING			// Mode for retyping a story
};

// Function to display game start notification
void GameStartNotification();

// Function to check if a file exists
// This function takes a string argument representing a file name and returns if it exists 
bool FileCheck(std::string fileName);

// Function to compare two strings while ignoring case sensitivity
// It takes in two string parameters, and 
// returns a boolean value indicating whether the two strings are equal or not, ignoring the case of the characters.
bool EqualsIgnoringCase(std::string compareWord, std::string userInput);

// Function to set the game mode based on user input
// It takes a string values from user, the value refers the game mode. 
// It returns the game mode as enum data type.
int GameModeSetting(std::string userInput);

// Function for creating a story
void CreateMode();

// Function for viewing an existing story
void ViewMode();

// Function to find and replace a placeholder in a string using user's input (from ReplaceString())
// It takes two string parameters to find Keyword using the tag( " < " ). 
void FindingPlaceHolder(std::string fileContents, std::string outputFileName);

// Function to replace a placeholder in a string with user input
// It takes a string parameters to replace the keyword (in the file) to user's input
// , and returns user's input 
std::string GetUserAnswer(std::string oldString);

// Function to write the story to a file
// It takes two string parameters "fileContents" has a whole string for a new story created by the user's answer.
// "outputFileName" is the name of ouput file that user made in a createMode();
void WriteStory(std::string fileContents, std::string outputFileName);

#endif