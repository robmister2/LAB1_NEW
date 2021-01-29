#include <iostream>
#include <vector>
#include "Token.h"


#ifndef UNTITLED_AUTOMATON_H
#define UNTITLED_AUTOMATON_H


class Automaton
{
protected:
    int inputRead = 0;
    int newLines = 0;
    TokenType type;
public:
    Automaton::Automaton();
    Automaton(TokenType type) { this->type = type; }
// Start the automaton and return the number of characters read
// read == 0 indicates the input was rejected
// read > 0 indicates the input was accepted
    virtual int Start(const std::string& input) = 0;
    virtual Token* CreateToken(std::string input, int lineNumber) {
        return new Token(input, lineNumber, type); }
    virtual int NewLinesRead() const { return newLines; }
};



#endif //UNTITLED_AUTOMATON_H
