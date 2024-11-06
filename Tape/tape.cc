

#include "tape.h"

Tape::Tape(const std::string& input, Symbol blankSymbol) {
  blankSymbol_ = blankSymbol;
  for (char symbol : input) {
    string_.push_back(Symbol(symbol));
  }
  string_.push_back(blankSymbol_);
  headPosition_ = 0;
}

void Tape::MoveHead(char movement) {
  if (movement == 'L') {
    --headPosition_;
    if (headPosition_ < 0) {
      string_.insert(string_.begin(), blankSymbol_);
      headPosition_ = 0;
    }
  } else if (movement == 'R') {
    ++headPosition_;
  }
}

std::ostream& operator<<(std::ostream& os, const Tape& tape) {
  int headPosition = tape.GetHeadPosition();
  for (int i = 0; i < tape.GetString().size(); i++) {
    Symbol currentSymbol = tape.GetString()[i];
    if (i == headPosition) {
      os << "→" << currentSymbol;
    } else {
      os << currentSymbol;
    }
  }
  return os;
}