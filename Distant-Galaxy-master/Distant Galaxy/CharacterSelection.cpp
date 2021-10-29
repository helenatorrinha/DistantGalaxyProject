#include<iostream>
#include<string>
#include <Windows.h>
#include"getCorrectValues.cpp"

using namespace std;

string OriginStories(int choice) {
	if (choice == 1)
		return "The story about how Sheila got here is very uncommon. There was "
			"a time and a place where a nuclear war got started and billions died."
			"One among those was a soldier that lost her head while closing the door "
			"of the last surviving bunker. She sacrificed herself to save everyone else "
			"and therefore the species of that planet made a ritual to bring her back to life. "
			"That brings us to today. Sheila’s spirit is traveling around the cosmos, "
			"in her soldier armor, looking for a bionic prosthesis to replace what once was her head.";
	else if (choice == 2)
		return "Stuart is a particular young turtkean with only 237 years of age. "
			"The turtkeans are known to have IQs averaging 396 that is double of the" 
			"highest ever IQ in Human history. Staurt was banned for life from his planet "
			"because he was playing around with nuclear bombs and accidently destroyed "
			"a whole planet. Nowadays, Stuart is lonely and going around the universe "
			"looking for friends or someone that cares about him.";
	else if (choice == 3)
		return "Azreal was once upon a time a god until a dramatic twist happened. "
			"He is the son of the creator of it all, but was punished because he got a mortal pregnant "
			"and his father banished him from the godlyhood and made him mortal so that he can see what god "
			"responsibilities are. Doing so, his father also killed his love and Azreal travels the universe "
			"searching for a way to get revenge on his father.";	
	
	return "Not an available character";
}

int CharacterSelection()
{
	std::cout << "Chose your character: (Sheila) - press 1, (Stuart) - press 2, (Azrael) - press 3\n";		
	string errorMessage = "Invalid choice\n Chose your character: (Sheila) - press 1, (Azmuth) - press 2, (Azrael) - press 3\n";
	int playerChoice = GetCorrectValues(errorMessage, {1,2,3});
	
	if (playerChoice == 1)
	{
		system("cls");
		std::cout << "You chose Sheila " << endl;
	}
	else if (playerChoice == 2)
	{
		system("cls");
		std::cout << "You chose Stuart " << endl;
	}
	else if (playerChoice == 3)
	{
		system("cls");
		std::cout << "You chose Azrael " << endl;
	}
	return playerChoice;
}
