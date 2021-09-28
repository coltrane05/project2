//
// Created by Colton Crapo on 9/13/21.
//

#ifndef PROJECT1_COMMAAUTOMATON_H
#define PROJECT1_COMMAAUTOMATON_H

#include "Automaton.h"

class CommaAutomaton : public Automaton {
private:

public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}

    void S0(const std::string& input);
};

#endif //PROJECT1_COMMAAUTOMATON_H
