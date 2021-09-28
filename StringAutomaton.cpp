//
// Created by Colton Crapo on 9/16/21.
//

#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (input[index] == '\'')  {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] != '\'' && index != input.size()) {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
    else {
        changeTokenType(TokenType::UNDEFINED);
    }

}

void StringAutomaton::S2(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
}