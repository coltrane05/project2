//
// Created by Colton Crapo on 9/16/21.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] != '\n' && input[index] != '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomaton::S3(const std::string &input) {
    if (input[index] != '|' && index != input.size()) {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S4(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        changeTokenType(TokenType::UNDEFINED);
    }
}

void CommentAutomaton::S4(const std::string& input) {
    if (input[index] != '|' && index != input.size()) {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S4(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        changeTokenType(TokenType::UNDEFINED);
    }
}

void CommentAutomaton::S5(const std::string& input) {
    if (input[index] != '#' && index != input.size()) {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S4(input);
    }
    else if (input[index] == '#') {
        inputRead++;
    }
    else {
        changeTokenType(TokenType::UNDEFINED);
    }
}
