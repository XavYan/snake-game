#pragma once

#include <Snake.h>

class Controller {
public:
	Controller() {}

	virtual int get_snake_view () const = 0;
};
