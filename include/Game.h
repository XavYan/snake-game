#pragma once

#include <Matrix.h>
#include <Cell.h>
#include <Snake.h>

#include <queue>
#include <utility>
#include <unistd.h>

#define TABLE_DIMENSION 6

class Game {
private:
	Matrix<Cell> table_;
	Snake snake_;

	std::queue<std::pair<int,int>> tail_;

public:
	Game (int x = 0, int y = 0);

	void start ();

	void free_last_cell ();
	void cell_to_tail (int x, int y);

	bool game_failed () const;

	void write (bool clear = false, std::ostream& os = std::cout) const;
};
