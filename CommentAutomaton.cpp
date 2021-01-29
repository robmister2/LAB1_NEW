//
// Created by Rob on 1/28/2021.
//

#include "CommentAutomaton.h"

CommentAutomaton::CommentAutomaton(TokenType tokenType) : Automaton(tokenType) {

}
int CommentAutomaton::Start(const string &input) {

    bool isMatch = true;
    inputRead = 0; // member variable inherited from Automaton class
    if(input[0] == '#'){
        if(input.size() > 1 && input[1] == '|'){
            inputRead = 2; //make up for first two skipped
            for (unsigned int i = 2; i < input.size()-1 && isMatch; i++){
                if(input.at(i) == '|' && input.at(i + 1) == '#'){ //if it's a block comment
                    isMatch = false;
                    inputRead += 2;

                }
                else{
                    inputRead++;
                }
            }
            if(isMatch){
                inputRead = -1; //reached EOF before it reached closing block comment XD
            }

        }
        else {
            for (unsigned int i = 0; i < input.size() && isMatch; i++) { //if it's line comment
                if (input[i] == '\n' || input[i] == EOF) {
                    isMatch = false;
                } else {
                    inputRead++;
                }
            }

        }
    }

    return inputRead;
}

