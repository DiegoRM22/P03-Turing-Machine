

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
  } else if (movement == 'S') { // Not necessary, but added for completeness
    headPosition_ = headPosition_;
  } else {
    std::cerr << "Invalid movement\n";
    exit(1);
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