#include <Game.h>

Game::Game (int x, int y, Controller* controller) : table_(TABLE_DIMENSION, TABLE_DIMENSION) {
  snake_.set_position(x, y);

  srand(time(NULL));

  if (!controller) {
    controller_ = new KeyboardController();
  } else {
    controller_ = controller;
  }
}

void Game::start () {

  write(true);

  // Creating the first apple
  create_apple ();

  while (!game_failed()) {
    usleep(300000);

    int last_x = snake_.x();
    int last_y = snake_.y();

    // here we set the view
    snake_.set_view(controller_->get_snake_view());

    snake_.advance();

    int state = table_(snake_.y(), snake_.x()).get_state();

    if (state == EMPTY_STATE && !tail_.empty()) {
      cell_to_tail(last_x, last_y);
      free_last_cell();
    }

    if (state == POINT_STATE) {
      cell_to_tail(last_x, last_y);
      create_apple();
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

void Game::create_apple () {
  std::vector<std::pair<int,int>> tail_positions = get_tail_positions();
  std::vector<std::pair<int,int>> available_positions;

  for (int i = 0; i < table_.rows(); i++) {
    for (int j = 0; j < table_.cols(); j++) {
      if (!in_array(std::pair<int,int>(j, i), tail_positions) && !(j == snake_.x() && i == snake_.y())) {
        available_positions.push_back(std::pair<int,int>(j, i));
      }
    }
  }

  int len = available_positions.size();
  std::pair<int,int> chosen = available_positions[rand() % len];
  table_(chosen.second, chosen.first).set_state(POINT_STATE);
}

std::vector<std::pair<int,int>> Game::get_tail_positions () const {
  std::queue<std::pair<int,int>> aux = tail_;
  std::vector<std::pair<int,int>> result(aux.size());
  
  for (int i = 0; !aux.empty(); i++) {
    result[i] = aux.front();
    aux.pop();
  }

  return result;
}

bool Game::in_array (std::pair<int,int> p, std::vector<std::pair<int,int>> arr) const {
  for (std::pair<int,int> value : arr) {
    if (p.first == value.first && p.second == value.second) {
      return true;
    }
  }
  return false;
}
