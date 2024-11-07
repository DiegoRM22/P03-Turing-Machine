/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional P03
  *
  * @author Diego Rodríguez Martín
  * @since 07/11/2024
  * @brief Implementación de la clase Transition.
  *
*/

#include <iostream>
#include <stack>
#include <vector>

#include "../Symbol/symbol.h"


#ifndef TRANSITION_H
#define TRANSITION_H

class Transition {
 public:
  Transition(const std::string& fromState, const std::string& toState, Symbol currentSymbol, Symbol toWriteSymbol, 
  char movement) : fromState_(fromState), toState_(toState), currentSymbol_(currentSymbol), toWriteSymbol_(toWriteSymbol), movement_(movement) {}
  // Getters
  std::string GetFromState() const { return fromState_; }
  std::string GetToState() const { return toState_; }
  Symbol GetCurrentSymbol() const { return currentSymbol_; }
  Symbol GetToWriteSymbol() const { return toWriteSymbol_; }
  char GetMovement() const { return movement_; }

 private:
  std::string fromState_;
  std::string toState_;
  Symbol currentSymbol_;
  Symbol toWriteSymbol_;
  char movement_;
};

std::ostream& operator<<(std::ostream& os, const Transition& transition);

#endif