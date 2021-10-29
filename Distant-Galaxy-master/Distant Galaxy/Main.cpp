#include<string>
#include<iostream>
#include<Windows.h>
#include <vector>

#include"CharacterDisplay.cpp"
#include"CharacterSelection.cpp"
#include"getCorrectValues.cpp"
#include"Map.cpp"
#include"Combat.cpp"
#include"StartingScreen.cpp"
#include "CharacterConstructor.h"
#include "StoryChecker.cpp"
#include "WonStoryChecker.cpp"
using namespace std;

int main() {
	CharacterConstructor player;
	CharacterConstructor monster;

	SetConsoleOutputCP(CP_UTF8);  //Convert output of console to support utf-8 to accept special characters

	StartingScreen();
	std::cout << "1 - Play game." << endl << "0 - Exit game.\n";
	string errorMessage = "Invalid choice, Please try again\n 1 - Play game. \n 0 - Exit game.\n";
	int choice = GetCorrectValues(errorMessage, {0,1});
	
	if (choice == 1)  //Starts the Game
	{
		std::cout << "Starting Game\n";
		system("cls");
		CharacterDisplay();
		
		int character = CharacterSelection(); //Returns chose character
		std::cout << OriginStories(character) << endl;
		system("pause");
		system("cls");
		int currentLevel = 1;
		
		//while the player hasnt finished all levels
		while (currentLevel <= 3)
		{
			currentLevel = movement(currentLevel); //Display the map and choose the level
			StoryBeforeLevel (currentLevel, character);
			player = ReturnCharacterValues (currentLevel, character);
			monster = ReturnMonsterValues (currentLevel);

			if (Combat(player, monster))  //If Won Combat 
			{
				cout << "\nYou killed the monster!";
				StoryAfterLevel(currentLevel, character);
				system("pause");
				cout << "Returning to map\n";
            	Sleep(5000);
				currentLevel++;
			}
			
		}		
	}
	else if (choice == 0) 
	{
		std::cout << "Exiting the game...\n";
	}
	return 0;
}
