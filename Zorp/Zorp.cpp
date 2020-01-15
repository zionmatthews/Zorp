#include <iostream>
#include "Game.h"

void main() {
	Game game;

	if (game.startup() == false)
		return;

	// game loop
	while (!game.isGameOver())
	{
		game.draw();

		game.update();
	} // end game loop

	std::cout << CSI << PLAYER_INPUT_Y << ";" << 0 << "H";	// jump to the correct location
	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program.";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}