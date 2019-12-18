

#include "pch.h"
#include <iostream>

void main()
{
	int height = 0;
	char firstLetterOfName = 0;
	int avatarHP = 0;

	std::cout << "Welcome to Zorp!" << std::endl;
	std::cout << "Zorp is a game of adventure, danger, and low cunning." << std::endl;
	std::cout << "It is definately not related to any other text-based adventure game." << std::endl;
	std::cout << "First, some questions..." << std::endl;
	std::cout << "How tall are you, in centimeters? " << std::endl;

	std::cin >> height;
	if (std::cin.fail()) {
		std::cout << "You have failed the first challenge and are eaten by a Pufferfish.....auh...augh. " << std::endl;
	}
	else {
		std::cout << "You entered " << height << std::endl;
	}


	std::cin.clear();
	//Stops the program from going into exit mode after input from height
	std::cin.ignore(std::cin.rdbuf() -> in_avail());

	std::cout << "What is the first letter of your name?" << std::endl;

	std::cin >> firstLetterOfName;

	if (std::cin.fail() || !isalpha(firstLetterOfName)) {
		std::cout << "You have failed the second challenge and are eaten by a AboAbuduAble." << std::endl;
	}
	else {
		std::cout << "You entered " << firstLetterOfName << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	if (firstLetterOfName != 0) {
		avatarHP = (float)height / (firstLetterOfName * 0.02f);
	}
	else {
		avatarHP = 0;
	}

	std::cout << std::endl << "Using a complex deterministic algorithm, it has been calculated that you have " << avatarHP << " hit"
		"points(s)." << std::endl;
	

	std::cout << std::endl << "Press 'Enter' to exit the program." << std::endl;
	std::cin.get();
	return;
}

