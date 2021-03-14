#include <iostream>
#include <string.h>

#include <Game.h>
#include <KeyboardController.h>

int main (int argc, char* argv[]) {
	KeyboardController* kb = new KeyboardController();
	Game game(1, 1, kb);
	game.start();
	std::cout << "Finished!\n";
}
