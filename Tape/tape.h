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

#ifndef TAPE_H
#define TAPE_H

#include <vector>

#include "../Symbol/symbol.h"

class Tape {
 public:
  Tape() {}
  Tape(const std::string& input, Symbol blankSymbol);

  // Getters
  Symbol GetSymbol() const { return string_[headPosition_]; }
  int GetHeadPosition() const { return headPosition_; }
  std::vector<Symbol> GetString() const { return string_; }
  // Setters
  void WriteSymbol(Symbol symbol) { string_[headPosition_] = symbol; }
  void MoveHead(char movement);
 private:
  std::vector<Symbol> string_;
  int headPosition_;
  Symbol blankSymbol_;
};

std::ostream& operator<<(std::ostream& os, const Tape& tape);

#endif