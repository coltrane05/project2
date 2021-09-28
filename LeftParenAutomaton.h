//
// Created by Colton Crapo on 9/13/21.
//

#ifndef PROJECT1_LEFTPARENAUTOMATON_H
#define PROJECT1_LEFTPARENAUTOMATON_H

#include "Automaton.h"

class LeftParenAutomaton : public Automaton {
private:

public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}

    void S0(const std::string& input);
};
#endif //PROJECT1_LEFTPARENAUTOMATON_H
