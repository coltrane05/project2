//
// Created by Colton Crapo on 9/28/21.
//
#include "Lexer.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
int main(int argc, const char* argv[]) {

    Lexer* lexer = new Lexer();

    string entireFile;
    stringstream ss;
    ifstream in(argv[1]);
    string currentLine;
    while (getline(in, currentLine)) {
        if (in.eof) {
            ss << currentLine;
        }
        else {
            ss << currentLine << endl;
        }
    }
    entireFile == ss.str();

    lexer->Run(entireFile);
}

