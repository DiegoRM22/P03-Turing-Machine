/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional P03
  *
  * @author Diego Rodríguez Martín
  * @since 07/11/2024
  * @brief Implementación de la clase TuringMachine.
  *
*/

#include <fstream>
#include <regex>

#include "turing_machine.h"

/**
 * Constructor de la clase TuringMachine.
 * @param fileName Nombre del archivo de configuración.
 * @return TuringMachine
 */
TuringMachine::TuringMachine(const std::string& fileName) {
  std::ifstream file(fileName);
  std::string line;
  std::regex commentLineRegexp("\\s*#.*");
  int counter = 0;
  std::string delimiter = " ";
  std::vector<State*> auxiliarStates;

  while (std::getline(file, line)) {
    if (std::regex_match(line, commentLineRegexp)) {
      continue;
    }
    ++counter;
    switch(counter) {
      case 1: {
        // Parsear la línea de estados
        while (line.size() > 0 && line.find(delimiter) != std::string::npos) {
          std::string stateIdentifier = line.substr(0, line.find(delimiter));
          auxiliarStates.push_back(new State(stateIdentifier));
          line.erase(0, line.find(delimiter) + delimiter.length());
        }
        auxiliarStates.push_back(new State(line));
        break;
      }
      case 2: {
        // Parsear la línea de alfabeto de entrada
        while (line.size() > 0 && line.find(delimiter) != std::string::npos) {
          std::string symbol = line.substr(0, line.find(delimiter));
          inputAlphabet_.AddSymbol(Symbol(symbol[0]));
          line.erase(0, line.find(delimiter) + delimiter.length());
        }
        inputAlphabet_.AddSymbol(Symbol(line[0]));
        break;
      }
      case 3: {
        // Parsear la línea de alfabeto de cinta
        while (line.size() > 0 && line.find(delimiter) != std::string::npos) {
          std::string symbol = line.substr(0, line.find(delimiter));
          tapeAlphabet_.AddSymbol(Symbol(symbol[0]));
          line.erase(0, line.find(delimiter) + delimiter.length());
        }
        tapeAlphabet_.AddSymbol(Symbol(line[0]));
        break;
      }
      case 4: {
        // Parsear el estado inicial
        initialState_ = line;
        break;
      }
      case 5: {
        // Parsear el símbolo blanco
        blankSymbol_ = Symbol(line[0]);
        if (!checkSymbol(blankSymbol_, tapeAlphabet_)) {
          std::cerr << "Error: Símbolo blanco no encontrado en el alfabeto de cinta.\n";
          exit(1);
        }
        break;
      }
      case 6: {
        // Parsear los estados de aceptación
        while (line.size() > 0 && line.find(delimiter) != std::string::npos) {
          std::string stateIdentifier = line.substr(0, line.find(delimiter));
          for (State* state : auxiliarStates) {
            if (state->getIdentifier() == stateIdentifier) {
              state->setAccepting(true);
            }
          }
          line.erase(0, line.find(delimiter) + delimiter.length());
        }
        for (State* state : auxiliarStates) {
          if (state->getIdentifier() == line) {
            state->setAccepting(true);
          }
        }
        break;
      }
      default: {
        // Parsear las transiciones
        std::string fromState = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        Symbol currentSymbol = Symbol(line[0]);
        line.erase(0, 2);
        std::string toState = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        Symbol toWriteSymbol = Symbol(line[0]);
        line.erase(0, 2);
        char movement = line[0];
        for (State* state : auxiliarStates) {
          if (state->getIdentifier() == fromState) {
            state->AddTransition(Transition(fromState, toState, currentSymbol, toWriteSymbol, movement));
          }
        }
        break;
      }
    }
  }
  for (State* state : auxiliarStates) {
    states_.insert(*state);
  }
  if (!checkState(initialState_)) {
    std::cerr << "Error: Estado inicial no encontrado en la lista de estados.\n";
    exit(1);
  }
  if (!CheckAlphabetsIntegrity()) {
    std::cerr << "Error: Alfabeto de entrada no contenido en el alfabeto de cinta.\n";
    exit(1);
  }
  for (State state : states_) {
    for (Transition transition : state.getTransitions()) {
      if (!checkTransition(transition)) {
        std::cerr << "Error: Transición: " << transition << " no válida.\n";
        exit(1);
      }
    }
  }
}

/**
 * Método que comprueba si una cadena es aceptada por la máquina de Turing.
 * @param input Cadena de entrada.
 * @return bool
 */
bool TuringMachine::isAccepted(const std::string& input) {
  tape_ = Tape(input, blankSymbol_);
  State currentState = *states_.begin();
  while (true) {
    Symbol currentSymbol = tape_.GetSymbol();
    bool transitionFound = false;
    // std::cout << tape_ << '\n';
    for (Transition transition : currentState.getTransitions()) {
      if (transition.GetFromState() == currentState.getIdentifier() && transition.GetCurrentSymbol() == currentSymbol) {
        // std::cout << "Transition: " << transition << '\n';
        currentState = *states_.find(State(transition.GetToState()));
        tape_.WriteSymbol(transition.GetToWriteSymbol());
        tape_.MoveHead(transition.GetMovement());
        transitionFound = true;
        break;
      }
    }
    if (!transitionFound) {
      std::cout << "Tape: " << tape_ << '\n';
      return currentState.isAccepting();
    }
    //std::cin.get();
  }
  
}

/**
 * Método que comprueba si un estado está en la lista de estados.
 * @param stateIdentifier Identificador del estado.
 * @return bool
 */
bool TuringMachine::checkState(const std::string& stateIdentifier) const {
  for (State state : states_) {
    if (state.getIdentifier() == stateIdentifier) {
      return true;
    }
  }
  return false;
}

/**
 * Método que comprueba si un símbolo está en el alfabeto.
 * @param symbol Símbolo a comprobar.
 * @param alphabet Alfabeto en el que comprobar.
 * @return bool
 */
bool TuringMachine::checkSymbol(const Symbol& symbol, const Alphabet& alphabet) const {
  for (Symbol symbolInAlphabet : alphabet.GetSymbols()) {
    if (symbol == symbolInAlphabet) {
      return true;
    }
  }
  return false;
}

/**
 * Método que comprueba si un movimiento es válido.
 * @param movement Movimiento a comprobar.
 * @return bool
 */
bool TuringMachine::checkMovement(const char movement) const {
  return movement == 'L' || movement == 'R' || movement == 'S';
}

/**
 * Método que comprueba si una transición es válida.
 * @param transition Transición a comprobar.
 * @return bool
 */
bool TuringMachine::checkTransition(const Transition& transition) const {
  return (checkState(transition.GetFromState()) && checkState(transition.GetToState()) && 
  checkSymbol(transition.GetCurrentSymbol(), tapeAlphabet_) && checkSymbol(transition.GetToWriteSymbol(), tapeAlphabet_) 
  && checkMovement(transition.GetMovement()));
}

/**
 * Método que comprueba si los alfabetos son coherentes.
 * @return bool
 */
bool TuringMachine::CheckAlphabetsIntegrity() const {
  // Si está en el alfabeto de entrada, tiene que estar en el alfabeto de cinta
  for (Symbol symbol : inputAlphabet_.GetSymbols()) {
    if (!checkSymbol(symbol, tapeAlphabet_)) {
      return false;
    }
  }
  return true;
}
