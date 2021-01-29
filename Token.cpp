//
// Created by rsmith10 on 1/26/2021.
//

#include "Token.h"

Token::Token() {

}

string Token::toString() {
    string output = "(";

    output += tokenToString(token);
    output += ",";

    output += "\"";
    output += input;
    output += "\",";

    output += std::to_string(line);
    output +=")";

    return output;
}

std::string Token::tokenToString(TokenType type)
{
    switch (type) {
        case COMMA: return "COMMA";
        case PERIOD: return "PERIOD";
        case Q_MARK: return "Q_MARK";
        case LEFT_PAREN: return "LEFT_PAREN";
        case RIGHT_PAREN: return "RIGHT_PAREN";
        case COLON: return "COLON";
        case COLON_DASH: return "COLON_DASH";
        case MULTIPLY: return "MULTIPLY";
        case ADD: return "ADD";
        case SCHEMES: return "SCHEMES";
        case FACTS: return "FACTS";
        case RULES: return "RULES";
        case QUERIES: return "QUERIES";
        case STRING: return "STRING";
        case COMMENT: return "COMMENT";
        case UNDEFINED: return "UNDEFINED";
        case END_OF_FILE: return "EOF";
        case ID: return "ID";
    };
    return "UNDEFINED";
}
