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
		case EMode::RETYPING:
			break;
		}
	}
}
