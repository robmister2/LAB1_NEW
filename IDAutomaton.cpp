//
// Created by Rob on 1/27/2021.
//

#include "IDAutomaton.h"

int IDAutomaton::Start(const string& input) {
    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    if(isalpha(input[0])){
        for (int i = 0; i < input.size() && isMatch; ++i){
            if(!isalnum(input[i])){
                isMatch = false;
            }
            else {
                inputRead++;
            }
        }

    }

    return inputRead;
}

IDAutomaton::IDAutomaton(TokenType tokenType) : Automaton(tokenType) {

}
