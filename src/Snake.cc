#include <Snake.h>

Snake::Snake(int x, int y, int view) {
  set_position(x, y);
  view_ = view;
}

void Snake::set_position(int x, int y) {
  x_ = x;
  y_ = y;
}

void Snake::set_view (int view) {
  view_ = view;
}

int Snake::x () const {
  return x_;
}

int Snake::y () const {
  return y_;
}

void Snake::advance () {
  if (view_ == UP) {
    y_--;
  }

  if (view_ == RIGHT) {
    x_++;
  }

  if (view_ == DOWN) {
    y_++;
  }
  
  if (view_ == LEFT) {
    x_--;
  }
}

void Snake::write (std::ostream& os) const {
  os << "◼";
}

std::ostream& operator<< (std::ostream& os, const Snake& snake) {
  snake.write(os);
  return os;
}
