//
// Created by Rob on 1/28/2021.
//

#include "StringAutomaton.h"

StringAutomaton::StringAutomaton(TokenType tokenType) : Automaton(tokenType) {

}

int StringAutomaton::Start(const string &input) {
    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    if(input[0] == '\''){
        if(input[1] == '\'' && input[2] != '\''){ //EMPTY STRINGGGGGGG
            return 2;
        }
        inputRead = 1; //account for shift in i
        for (int i = 1; i < input.size() - 1 && isMatch; ++i){
            if((input[i]) == '\''){
                inputRead++;
                if(input[i + 1] != '\''){
                    isMatch = false;
                }
                else{ // In case of '' in middle of string :c
                    inputRead++;
                    i += 1;
                }
            }
            else {
                inputRead++;
            }
        }
        if (isMatch){ //if the string was never closed
            return -1; //so we can tell Lexer to make the rest of the string undefined
        }

    }

    return inputRead;

}
