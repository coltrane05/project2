#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    int lineNumber;
    int maxRead;
    int maxAutomaton;


    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    
    std::string toString() const;

    std::vector<TokenType> getTokenTypes() {
        std::vector<TokenType> tokenTypes;
        for (size_t i = 0; i < tokens.size(); i++) {
            tokenTypes[i] = tokens[i]->getTokenType();
        }
        return tokenTypes;
    }

};

#endif // LEXER_H

