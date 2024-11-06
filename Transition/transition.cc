
#include "transition.h"

/**
 * Sobrecarga del operador de inserción para imprimir la transición.
 */
std::ostream& operator<<(std::ostream& os, const Transition& transition) {
  os << "δ(" << transition.GetFromState() << ", " << transition.GetCurrentSymbol() << ") = (" << 
  transition.GetToState() << ", " << transition.GetToWriteSymbol() << ", " << transition.GetMovement() << ")";
  return os;
}