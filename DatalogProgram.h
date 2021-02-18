#include <vector>
#include "Parameter.h"
#include "Parser.h"
#include "Predicate.h"
#include "Rule.h"
using namespace std;


#ifndef LAB1_NEW_DATALOGPROGRAM_H
#define LAB1_NEW_DATALOGPROGRAM_H


class DatalogProgram {
private:
    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<Predicate*> queries;
    vector<Rule*> rules;

};


#endif //LAB1_NEW_DATALOGPROGRAM_H
