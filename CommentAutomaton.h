//
// Created by Colton Crapo on 9/16/21.
//

#ifndef PROJECT1_COMMENTAUTOMATON_H
#define PROJECT1_COMMENTAUTOMATON_H
#include "Automaton.h"

class CommentAutomaton : public Automaton {
private:
    void changeTokenType(TokenType newTokenType) {
        type = newTokenType;
    }
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}

    void S0(const std::string& input);
};
#endif //PROJECT1_COMMENTAUTOMATON_H
