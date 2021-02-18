#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Lexer.h"
#include "Parser.h"

int main (int argc, char* argv[]) {

    //Take in input file from argument passed into main
    std::string inputFile = argv[1];

    //Declare input file stream and pass input file
    std::ifstream ifs(inputFile);

    /*
    Open the input file using the file stream and then pass the
    contents of the file into a string called "inputString"
    */

    std::string inputString;
    inputString.assign( (std::istreambuf_iterator<char>(ifs) ),
                        (std::istreambuf_iterator<char>()    ) );

    Lexer *tokenizer = new Lexer;
    tokenizer->Run(inputString);

    vector<Token*> allTokens = tokenizer->GetTokens();
    //std::cout << tokenizer->toString();

    for (int i = 0; i < allTokens.size(); i++){
        if (allTokens.at(i)->getTokenType() == COMMENT){
            allTokens.erase(allTokens.begin() + i);
            i--;
        }
    }

    Parser *parser = new Parser;
    try{
        parser->parse(allTokens);
    }
    catch (...){
        cout << "Failure!" << endl;
        cout << "  ";
        cout << allTokens.front()->toString() << endl;
    }

    delete tokenizer;
    delete parser;

    return 0;
}