#pragma once

#include <iostream>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

class Snake {
private:
	int x_;
	int y_;
	int view_;

public:
	Snake(int x = 0, int y = 0, int view = RIGHT);

	void set_position (int x, int y);
	void set_view (int view);

	int x () const;
	int y () const;

	void advance ();

	void write (std::ostream& os) const;
};

std::ostream& operator<< (std::ostream& os, const Snake& snake);