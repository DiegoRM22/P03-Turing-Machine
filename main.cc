
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