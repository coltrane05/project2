#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "FactsAutomaton.h"
#include "IdAutomaton.h"
#include "LeftParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "QueriesAutomaton.h"
#include "RightParenAutomaton.h"
#include "RulesAutomaton.h"
#include "SchemesAutomaton.h"
#include "AddAutomaton.h"
#include "CommentAutomaton.h"
#include "StringAutomaton.h"
#include <sstream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    automata.clear();
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new FactsAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new StringAutomaton());
}

void Lexer::Run(std::string& input) {
    lineNumber = 1;
    while(input.size() > 0) {
        maxRead = 0;
        maxAutomaton = 0;

        while ((input[0] == ' ') | (input[0] == '\n') | (input[0] == '\t')) {
            if (input [0] == '\n') {
                lineNumber++;
            }
            input.erase(0,1);
        }

        for (size_t i = 0; i < automata.size(); i++) {
            int inputRead;
            inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = i;
            }
        }

        if (maxRead > 0) {
            std::string tokenString(input, 0, maxRead);
            tokens.push_back(automata.at(maxAutomaton)->CreateToken(tokenString, lineNumber));
            lineNumber = lineNumber + automata.at(maxAutomaton)->NewLinesRead();
        }
        else {
            maxRead = 1;
            std::string tokenString(input, 0, maxRead);
            if (tokenString != "") {
                tokens.push_back(new Token(TokenType::UNDEFINED, tokenString, lineNumber));
            }
        }
        input.erase(0,maxRead);
    }
    tokens.push_back(new Token(TokenType::EOF_TOKEN, "", lineNumber));
}

std::string Lexer::toString() const {
    std::ostringstream oss;
    for (size_t i = 0; i < tokens.size(); i++) {
        oss << tokens.at(i)->toString() << std::endl;
    }

    oss << "Total Tokens = " << tokens.size();

    return oss.str();
}
/*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
