/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional P03
  *
  * @author Diego Rodríguez Martín
  * @since 07/11/2024
  * @brief Implementación de la clase tape.
  *
*/

#include "tape.h"

/**
 * Constructor de la clase Tape.
 * @param input Cadena de entrada.
 * @param blankSymbol Símbolo blanco.
 * @return Tape
 */
Tape::Tape(const std::string& input, Symbol blankSymbol) {
  blankSymbol_ = blankSymbol;
  for (char symbol : input) {
    string_.push_back(Symbol(symbol));
  }
  string_.push_back(blankSymbol_);
  headPosition_ = 0;
}

/**
 * Método que mueve la cabeza de la cinta.
 * @param movement Movimiento de la cabeza.
 */
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

/**
 * Sobrecarga del operador de inserción para imprimir la cinta.
 */
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