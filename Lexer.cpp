
#include <cctype>
#include "Lexer.h"

using namespace std;

void Lexer::Run(string &inputString) {
    int lineNumber = 1;
    int totalLines = 1;

    //count total lines read
    for (int i = 0; i < (int) inputString.length(); i++) {
        if (inputString[i] == '\n') {
            totalLines++;
        }
    }

    //if input is empty string
    if (totalLines == 1) {
        if (inputString.empty()) {
            Token *eofToken = new Token("", totalLines, END_OF_FILE);
            tokens.push_back(eofToken);
        }
    }

    //loop through the entire input
    while (inputString.size() > 0) {
        int testNums = removeWhitespace(inputString);
        lineNumber += testNums;
        int maxChar = 0;
        int maxAuto = 0;
        //run through the automata
        for (unsigned int i = 0; i < automata.size(); i++) {
            int testChar = automata.at(i)->Start(inputString);

            if (testChar > maxChar) {
                maxChar = testChar;
                maxAuto = i;
            }
            if (testChar == -1){
                maxChar = testChar; //in case of a broken string / comment
                break;
            }
        }
        string tokenString = "";
        if(maxChar == -1){
            tokens.push_back(new Token(inputString, lineNumber, UNDEFINED)); //ILL TAKE IT ALL
            maxChar = inputString.size() - 1; //erase rest of string except EOF
            tokenString = inputString.substr(0, maxChar);
        }
        else if(maxChar == 0){ //UNDEFINED CHARACTERS
            maxChar = 1;
            tokenString = inputString.substr(0, maxChar);
            if(inputString.size() == 0){
                tokens.push_back(new Token(tokenString, lineNumber, END_OF_FILE));
            }
            else {
                tokens.push_back(new Token(tokenString, lineNumber, UNDEFINED));
            }
        }
        else {
            tokenString = inputString.substr(0, maxChar);
            tokens.push_back(automata.at(maxAuto)->CreateToken(tokenString, lineNumber));

        }
        for (unsigned int i = 0; i < tokenString.size(); i++) { //Account for lines IN the token for next one
            if (tokenString.at(i) == '\n') {
                lineNumber++;
            }
        }
        inputString.erase(0, maxChar);
    }
}

string Lexer::toString() {
    string output = "";
    for (unsigned int i = 0; i < tokens.size(); ++i){
        output += tokens.at(i)->toString();
        output += "\n";
    }
    output += "Total Tokens = ";
    output += std::to_string(tokens.size());
    return output;
}
int Lexer::removeWhitespace(string& input){
    int count = 0;
    int lineNums = 0;
    for (unsigned int i = 0; i < input.size(); i++){
        if(isspace(input.at(i))){
            count += 1;
            if(input.at(i) == '\n') {
                lineNums++;
            }
        }
        else {
            break;
        }
    }
    input.erase(0, count);
    return lineNums;
}
