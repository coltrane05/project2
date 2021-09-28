//
// Created by Colton Crapo on 9/13/21.
//

#ifndef PROJECT1_MULTIPLYAUTOMATON_H
#define PROJECT1_MULTIPLYAUTOMATON_H

#include "Automaton.h"

class MultiplyAutomaton : public Automaton {
private:

public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}

    void S0(const std::string& input);
};
#endif //PROJECT1_MULTIPLYAUTOMATON_H
