#pragma once

#include <iostream>

#define EMPTY_STATE 0
#define POINT_STATE 1
#define TAIL_STATE 2

class Cell {
private:
	int state_;

public:
	Cell(int state = EMPTY_STATE);

	void set_state (int state);
	int get_state () const;

	void write (std::ostream& os = std::cout) const;
};

std::ostream& operator<< (std::ostream& os, const Cell& cell);