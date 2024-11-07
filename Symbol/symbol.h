/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional P03
  *
  * @author Diego Rodríguez Martín
  * @since 07/11/2024
  * @brief Implementación de la clase Symbol
  *
*/

#include <iostream>

#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol {
 public:
  Symbol() {}
  Symbol(char symbol) : symbol(symbol) {}
  char GetSymbol() const { return symbol; }
  void GetSymbol(char symbol) { this->symbol = symbol; }
  bool operator<(const Symbol& other) const { return symbol < other.GetSymbol(); }
  bool operator==(const Symbol& other) const { return symbol == other.GetSymbol(); }

 private:
  char symbol;
};

std::ostream& operator<<(std::ostream& os, const Symbol& symbol);

#endif