#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    EOF_TOKEN,
    UNDEFINED
};

class Token
{
private:
    TokenType myTokenType;
    std::string myDescription;
    int lineNumber;


public:
    Token(TokenType type, std::string description, int line);

    std::string toString() const;

    TokenType getTokenType() {
        return myTokenType;
    }
    std::string getDescription() {
        return myDescription;
    }
    int getLineNumber() {
        return lineNumber();
    }
};

#endif // TOKEN_H

