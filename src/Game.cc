#include <Game.h>

Game::Game (int x, int y) : table_(TABLE_DIMENSION, TABLE_DIMENSION) {
  snake_.set_position(x, y);
}

void Game::start () {
  table_(1, 2).set_state(POINT_STATE);
  table_(1, 4).set_state(POINT_STATE);

  write(true);

  while (!game_failed()) {
    usleep(500000);

    int last_x = snake_.x();
    int last_y = snake_.y();

    if (snake_.x() == table_.cols() - 1) {
      snake_.set_view(DOWN);
    }

    if (snake_.y() == table_.rows() - 1) {
      snake_.set_view(LEFT);
    }

    if (snake_.x() == 0) {
      snake_.set_view(UP);
    }

    if (snake_.y() == 0) {
      snake_.set_view(RIGHT);
    }

    snake_.advance();

    int state = table_(snake_.y(), snake_.x()).get_state();

    if (state == EMPTY_STATE && !tail_.empty()) {
      cell_to_tail(last_x, last_y);
      free_last_cell();
    }

    if (state == POINT_STATE) {
      cell_to_tail(last_x, last_y);
    }

    if (state == TAIL_STATE) {
      return;
    }

    write(true);
  }
}

void Game::free_last_cell () {
  std::pair<int,int> p = tail_.front();
  tail_.pop();
  table_(p.second, p.first).set_state(EMPTY_STATE);
}

void Game::cell_to_tail (int x, int y) {
  tail_.push(std::pair<int,int>(x, y));
  table_(y, x).set_state(TAIL_STATE);
}

bool Game::game_failed () const {
  return snake_.x() < 0 || snake_.y() < 0 || snake_.x() >= table_.cols() || snake_.y() >= table_.rows();
}

void Game::write (bool clear, std::ostream& os) const {

  if (clear) {
    os << "\x1b[2J";
    os << "\x1b[H";
  }

  for (int i = 0; i < table_.rows(); i++) {
    os << "|";
    for (int j = 0; j < table_.cols(); j++) {
      if (snake_.x() == j && snake_.y() == i) {
        os << snake_;
      } else {
        os << table_(i, j);
      }
      os << "|";
    }
    os << '\n';
  }
}
