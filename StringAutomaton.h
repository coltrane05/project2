//
// Created by Colton Crapo on 9/16/21.
//

#ifndef PROJECT1_STRINGAUTOMATON_H
#define PROJECT1_STRINGAUTOMATON_H

#include "Automaton.h"

class StringAutomaton : public Automaton {
private:
    void changeTokenType(TokenType newTokenType) {
        type = newTokenType;
    }
    void S1(const std::string& input);
    void S2(const std::string& input);
public:
    StringAutomaton() : Automaton(TokenType::STRING) {}

    void S0(const std::string& input);
};
#endif //PROJECT1_STRINGAUTOMATON_H
