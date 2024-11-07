/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional P03
  *
  * @author Diego Rodríguez Martín
  * @since 07/11/2024
  * @brief Implementación de la clase State.
  *
*/

#include "state.h"

/**
 * Sobrecarga del operador de inserción para imprimir el estado.
 */
std::ostream& operator<<(std::ostream& os, const State& state) {
  os << state.getIdentifier();
  os << " Transiciones: ";
  for (Transition transition : state.getTransitions()) {
    os << transition << '\n';
  }
  return os;
}