//
// Created by Colton Crapo on 9/15/21.
//

#include "IdAutomaton.h"

void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    if (isalnum(input.at(index))) {
        inputRead++;
        index++;
        S1(input);
    }
}