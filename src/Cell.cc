#include <Cell.h>

Cell::Cell(int state) {
  set_state(state);
}

void Cell::set_state (int state) {
  state_ = state;
}

int Cell::get_state () const {
  return state_;
}

void Cell::write (std::ostream& os) const {
  if (state_ == EMPTY_STATE) {
    os << " ";
  }
  
  if (state_ == POINT_STATE) {
    os << "▪";
  }

  if (state_ == TAIL_STATE) {
    os << "◼";
  }
}

std::ostream& operator<< (std::ostream& os, const Cell& cell) {
  cell.write(os);
  return os;
}