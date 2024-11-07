
#include <fstream>
#include <regex>

#include "turing_machine.h"

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
}


bool TuringMachine::isAccepted(const std::string& input) {
  tape_ = Tape(input, blankSymbol_);
  State currentState = *states_.begin();
  while (true) {
    Symbol currentSymbol = tape_.GetSymbol();
    bool transitionFound = false;
    std::cout << tape_ << '\n';
    for (Transition transition : currentState.getTransitions()) {
      if (transition.GetFromState() == currentState.getIdentifier() && transition.GetCurrentSymbol() == currentSymbol) {
        std::cout << "Transition: " << transition << '\n';
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

