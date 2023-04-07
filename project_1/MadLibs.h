#ifndef ADD_H
#define ADD_H

// Enumeration for different game modes
enum EMode
{
	CREATEMODE = 1, // Mode for creating a story
	VIEWMODE, // Mode for viewing an existing story
	QUIT, // Mode for quitting the program
	RETYPING // Mode for retyping a story
};

// Function to display game start notification
void GameStartNotification();

// Function to check if a file exists
bool FileCheck(std::string fileName);

// Function to compare two strings while ignoring case sensitivity
bool EqualsIgnoringCase(std::string compareWord, std::string userInput);

// Function to set the game mode based on user input
int GameModeSetting(std::string userInput);

// Function for creating a story
void CreateMode();

// Function for viewing an existing story
void ViewMode();

// Function to find and replace a placeholder in a string
void FindingPlaceHolder(std::string fileContents, std::string outputFileName);

// Function to replace a placeholder in a string with user input
std::string ReplaceString(std::string oldString);

// Function to write the story to a file
void WriteStory(std::string fileContents, std::string outputFileName);

#endif