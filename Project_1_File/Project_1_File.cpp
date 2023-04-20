/*
* Minsu Jung
* CS 132 Project 1
* April 8
* This code is the main function for a game that prompts the user to ...
* select a game mode (create, view, or quit) and executes the corresponding function. ... 
* It loops continuously until the user chooses to quit.
*/
#include <iostream>
#include <string>
#include "MadLibs.h"

// Main function for the game
int main()
{
	GameStartNotification();	// Notify the start of the game
	std::string userInput;

	// Game processing loop
	while (true)
	{
		std::cout << "Create, view or quit? ";
		std::getline(std::cin, userInput);
		int gameMode = GameModeSetting(userInput);

		// Switch between game modes based on user input
		switch (gameMode)
		{
		case EMode::CREATEMODE:
			CreateMode();
			break;
		case EMode::VIEWMODE:
			ViewMode();
			break;
		case EMode::QUIT:
			exit(0);
			break;
		case EMode::RETYPING:	// It returns without any function and receives the user's input again.
			break;
		}
	}
}
