#pragma once

#include <thread>
#include <mutex>
#include <cctype>

#include <Controller.h>
#include <Snake.h>
#include <BufferToggle.h>

class KeyboardController : public Controller {
private:
	char last_view_;

	std::thread* listener_;
	std::mutex mutex_;
	bool stop_;

public:
	KeyboardController();
	~KeyboardController();

	virtual int get_snake_view () const;

	friend void threadListenToInput (KeyboardController& controller);

private:
	bool isValidWay (char c);
};

void threadListenToInput (KeyboardController& controller);
