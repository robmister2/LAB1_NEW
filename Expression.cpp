//
// Created by Rob on 2/18/2021.
//

#include "Expression.h"

Expression::Expression() {

}

Expression::Expression(Parameter *parameter1, TokenType oper, Parameter* parameter2) {
    param1 = parameter1;
    param2 = parameter2;
    op = oper;
    isConstant = false;

}

string Expression::toString() {
    string output;
    output += "(";
    output += param1->toString();
     switch(op) {
         default:
             break;
         case ADD:
             output += "+";
             break;
         case MULTIPLY:
             output += "*";
             break;
     }
    output += param2->toString();
    output += ")";

    return output;

}
