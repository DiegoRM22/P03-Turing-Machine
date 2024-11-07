/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional P03
  *
  * @author Diego Rodríguez Martín
  * @since 07/11/2024
  * @brief programa principal que ejecuta la máquina de Turing.
  *
*/

#include <iostream>

#include "TuringMachine/turing_machine.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Uso: " << argv[0] << " <archivo_automata> <cadena1> [<cadena2> ...] [--trace]" << std::endl;
    return 1;
  }
  std::string fileName = argv[1];
  std::string input = argv[2];

  TuringMachine turingMachine(fileName);

  // Iterates over the input strings
  for (int i = 2; i < argc; i++) {
    std::string input = argv[i];
    std::cout << "Cadena: " << input << ' ';
    if (turingMachine.isAccepted(input)) {
      std::cout << "ACEPTADA\n";
    } else {
      std::cout << "RECHAZADA\n";
    }
  }



  
  return 0;
}