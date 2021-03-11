#include <iostream>

#include <Game.h>

int main (int argc, char* argv[]) {
	Game game(1, 1);
	game.start();
	std::cout << "Finished!";
}
