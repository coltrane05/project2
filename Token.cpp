#include "Token.h"
#include <sstream>

Token::Token(TokenType type, std::string description, int line) {
    myTokenType = type;
    myDescription = description;
    lineNumber = line;
}

std::string Token::toString() const {
    std::ostringstream oss;
    oss << "(";
    if (myTokenType == TokenType::COLON) {
        oss << "COLON,";
    }
    else if (myTokenType == TokenType::COLON_DASH) {
        oss << "COLON_DASH,";
    }
    else if (myTokenType == TokenType::QUERIES) {
        oss << "QUERIES,";
    }
    else if (myTokenType == TokenType::RULES) {
        oss << "RULES,";
    }
    else if (myTokenType == TokenType::FACTS) {
        oss << "FACTS,";
    }
    else if (myTokenType == TokenType::SCHEMES) {
        oss << "SCHEMES,";
    }
    else if (myTokenType == TokenType::ADD) {
        oss << "ADD,";
    }
    else if (myTokenType == TokenType::MULTIPLY) {
        oss << "MULTIPLY,";
    }
    else if (myTokenType == TokenType::ID) {
        oss << "ID,";
    }
    else if (myTokenType == TokenType::RIGHT_PAREN) {
        oss << "RIGHT_PAREN,";
    }
    else if (myTokenType == TokenType::LEFT_PAREN) {
        oss << "LEFT_PAREN,";
    }
    else if (myTokenType == TokenType::UNDEFINED) {
        oss << "UNDEFINED,";
    }
    else if (myTokenType == TokenType::Q_MARK) {
        oss << "Q_MARK,";
    }
    else if (myTokenType == TokenType::EOF_TOKEN) {
        oss << "EOF,";
    }
    else if (myTokenType == TokenType::COMMA) {
        oss << "COMMA,";
    }
    else if (myTokenType == TokenType::PERIOD) {
        oss << "PERIOD,";
    }
    else if (myTokenType == TokenType::COMMENT) {
        oss << "COMMENT,";
    }
    else if (myTokenType == TokenType::STRING) {
        oss << "STRING,";
    }
    oss << "\"" << myDescription << "\"," << lineNumber << ")";

    return oss.str();
}
