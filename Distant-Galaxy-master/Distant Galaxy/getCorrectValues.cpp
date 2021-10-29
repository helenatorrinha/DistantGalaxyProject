#ifndef getCorrecValues_cpp
#define getCorrecValues_cpp

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

int GetCorrectValues(string errorMessage, std::vector<int> choices) {
	int choice;
	std::cin >> choice;
	bool isValid = find(choices.begin(), choices.end(), choice) != choices.end();
	while (isValid == false)
	{
		std::cout << errorMessage;
		std::cin >> choice;
		isValid = find(choices.begin(), choices.end(), choice) != choices.end();
	}
	return choice;
}
#endif