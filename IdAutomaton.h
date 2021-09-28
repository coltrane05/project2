//
// Created by Colton Crapo on 9/15/21.
//

#ifndef PROJECT1_IDAUTOMATON_H
#define PROJECT1_IDAUTOMATON_H

#include "Automaton.h"
#include <cctype>

class IdAutomaton : public Automaton {
private:
    void S1(const std::string& input);

public:
    IdAutomaton() : Automaton(TokenType::ID) {}

    void S0(const std::string& input);
};
#endif //PROJECT1_IDAUTOMATON_H
