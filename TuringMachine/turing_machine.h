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

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include "../State/state.h"
#include "../Alphabet/alphabet.h"
#include "../Symbol/symbol.h"
#include "../Transition/transition.h"
#include "../Tape/tape.h"

class TuringMachine {
 public:
  TuringMachine(const std::string& fileName);
  
  bool isAccepted(const std::string& input);

  // Getters
  std::set<State> GetStates() const { return states_; }
  Alphabet GetInputAlphabet() const { return inputAlphabet_; }
  Alphabet GetTapeAlphabet() const { return tapeAlphabet_; }
  std::string GetInitialState() const { return initialState_; }
  Symbol GetBlankSymbol() const { return blankSymbol_; }

  bool checkState(const std::string& stateIdentifier) const;
  bool checkSymbol(const Symbol& symbol, const Alphabet& alphabet) const;
  bool checkTransition(const Transition& transition) const;
  bool checkMovement(const char movement) const;
  bool CheckAlphabetsIntegrity() const;


  
 private:
  std::set<State> states_;
  Alphabet inputAlphabet_;
  Alphabet tapeAlphabet_;
  std::string initialState_;
  Symbol blankSymbol_;
  Tape tape_;
};




#endif