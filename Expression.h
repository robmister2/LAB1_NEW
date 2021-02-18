
#ifndef LAB1_NEW_EXPRESSION_H
#define LAB1_NEW_EXPRESSION_H
#include "Parameter.h"
#include "Token.h"

class Expression:
        public Parameter{

private:
Parameter* param1;
Parameter* param2;
TokenType op;

public:
    Expression();
    Expression(Parameter* parameter1, TokenType oper, Parameter* parameter2);
    string toString();


};


#endif //LAB1_NEW_EXPRESSION_H
