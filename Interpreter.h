//
// Created by Rob on 3/11/2021.
//

#ifndef LAB1_NEW_INTERPRETER_H
#define LAB1_NEW_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include <iostream>


class Interpreter {
private:
    DatalogProgram* program;
    Database* database;
public:
    Interpreter(DatalogProgram* datalogProgram, Database* database1);
    void run ();
    Relation evaluatePredicate(Predicate query);
    string toString();

};


#endif //LAB1_NEW_INTERPRETER_H
