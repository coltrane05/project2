//
// Created by Colton Crapo on 9/13/21.
//

#ifndef PROJECT1_QMARKAUTOMATON_H
#define PROJECT1_QMARKAUTOMATON_H

#include "Automaton.h"

class QMarkAutomaton : public Automaton {
private:

public:
    QMarkAutomaton() : Automaton(TokenType::Q_MARK){}

    void S0(const std::string& input);
};
#endif //PROJECT1_QMARKAUTOMATON_H
