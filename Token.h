#include <string>
using namespace std;
#ifndef UNTITLED_TOKEN_H
#define UNTITLED_TOKEN_H


enum TokenType{COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, END_OF_FILE};
//enum stringToken{schemes, facts, rules, queries, };

class Token {
protected:
    TokenType token;
    string input;
    int line;
public:
    Token();
    Token(string name, int lineNum, TokenType tok  ){
        token = tok;
        input = name;
        line = lineNum;
    }

    string toString();


    string tokenToString(TokenType type);
};


#endif //UNTITLED_TOKEN_H
