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

#include "transition.h"

/**
 * Sobrecarga del operador de inserción para imprimir la transición.
 */
std::ostream& operator<<(std::ostream& os, const Transition& transition) {
  os << "δ(" << transition.GetFromState() << ", " << transition.GetCurrentSymbol() << ") = (" << 
  transition.GetToState() << ", " << transition.GetToWriteSymbol() << ", " << transition.GetMovement() << ")";
  return os;
}