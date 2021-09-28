//
// Created by Colton Crapo on 9/13/21.
//

#ifndef PROJECT1_SCHEMESAUTOMATON_H
#define PROJECT1_SCHEMESAUTOMATON_H

#include "Automaton.h"

class SchemesAutomaton : public Automaton {
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);

public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}

    void S0(const std::string& input);
};

#endif //PROJECT1_SCHEMESAUTOMATON_H
