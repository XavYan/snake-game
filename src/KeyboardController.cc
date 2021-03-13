#include <KeyboardController.h>

KeyboardController::KeyboardController() : Controller() {
  last_view_ = 'D';

  // Creamos un hilo que vaya escuchando y actualizando el ultimo valor de la snake
  stop_ = false;
  listener_ = new std::thread (&threadListenToInput, std::ref(*this));
}

KeyboardController::~KeyboardController() {
  stop_ = true;
  listener_->join();
}

int KeyboardController::get_snake_view () const {
  switch (last_view_) {
    case 'W':
      return UP;
    case 'D':
      return RIGHT;
    case 'S':
      return DOWN;
    case 'A':
      return LEFT;
  }
  return UP;
}

bool KeyboardController::isValidWay (char c) {

  c = toupper(c);
  switch (last_view_) {
    case 'W':
    case 'S':
      return (c == 'A' || c == 'D') ? true : false;
    case 'A':
    case 'D':
      return (c == 'W' || c == 'S') ? true : false;
  }
  return false;
}

void threadListenToInput (KeyboardController& controller) {

  BufferToggle bt;
  bt.off();

  while (!controller.stop_) {
    char c;
		if (controller.isValidWay(c = std::getchar())) {
      std::lock_guard<std::mutex> guard(controller.mutex_);
      controller.last_view_ = toupper(c);
		}
	}
}