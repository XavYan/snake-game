#include <iostream>
#include <string.h>

#include <Game.h>
#include <KeyboardController.h>

int main (int argc, char* argv[]) {
	KeyboardController* kb = new KeyboardController();
	Game game(1, 1, kb);
	game.start();
	std::cout << "Finished!\n";

	// KeyboardController controller;

	// int last_view = RIGHT;

	// while (true) {
	// 	int c = controller.get_snake_view();
	// 	if (c != last_view) {
	// 		std::cout << "Se ha detectado un cambio! Sentido actual: ";
	// 		switch (c) {
	// 			case UP:
	// 				std::cout << "UP";
	// 				break;
	// 			case RIGHT:
	// 				std::cout << "RIGHT";
	// 				break;
	// 			case DOWN:
	// 				std::cout << "DOWN";
	// 				break;
	// 			case LEFT:
	// 				std::cout << "LEFT";
	// 		}
	// 		std::cout << '\n';
	// 		last_view = c;
	// 	}
	// }
}
