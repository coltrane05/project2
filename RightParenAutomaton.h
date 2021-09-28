//
// Created by Colton Crapo on 9/13/21.
//

#ifndef PROJECT1_RIGHTPARENAUTOMATON_H
#define PROJECT1_RIGHTPARENAUTOMATON_H

#include "Automaton.h"

class RightParenAutomaton : public Automaton {
private:

public:
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN){}

    void S0(const std::string& input);
};
#endif //PROJECT1_RIGHTPARENAUTOMATON_H
