//
// Created by Colton Crapo on 9/13/21.
//

#ifndef PROJECT1_PERIODAUTOMATON_H
#define PROJECT1_PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton {
private:

public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}

    void S0(const std::string& input);
};
#endif //PROJECT1_PERIODAUTOMATON_H
