/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional P03
  *
  * @author Diego Rodríguez Martín
  * @since 07/11/2024
  * @brief Implementación de la clase Alphabet
  *
*/

#include <iostream>
#include <set>

#include "../Symbol/symbol.h"

#ifndef ALPHABET_H
#define ALPHABET_H

class Alphabet {
 public:
  Alphabet() {}
  Alphabet(std::set<Symbol> symbols) : symbols_(symbols) {}
  std::set<Symbol> GetSymbols() const { return symbols_; }
  void AddSymbol(Symbol symbol) { symbols_.insert(symbol); }
 private:
  std::set<Symbol> symbols_;
};

#endif