#pragma once

#include <Matrix.h>
#include <Cell.h>
#include <Snake.h>
#include <KeyboardController.h>

#include <queue>
#include <utility>
#include <vector>
#include <unistd.h>

#define TABLE_DIMENSION 17

class Game {
private:
	Matrix<Cell> table_;
	Snake snake_;

	Controller* controller_;

	std::queue<std::pair<int,int>> tail_;

public:
	Game (int x = 0, int y = 0, Controller* controller = nullptr);

	void start ();

	void free_last_cell ();
	void cell_to_tail (int x, int y);

	bool game_failed () const;

	void write (bool clear = false, std::ostream& os = std::cout) const;

private:
	void create_apple ();
	std::vector<std::pair<int,int>> get_tail_positions () const;
	bool in_array (std::pair<int,int> p, std::vector<std::pair<int,int>> arr) const;
};
