//
// Created by Rob on 2/18/2021.
//

#include "Predicate.h"

string Predicate::toString() {
    string output;
    output += name;
    output += "(";
    for(unsigned int i = 0; i < parameters.size(); ++i){
        output += parameters.at(i)->toString();
        if (i+1 != parameters.size()) {
            output += ",";
        }
    }
    output += ")";

    return output;
}

Predicate::Predicate(string name1, vector<Parameter *> parameters1) {
    name = name1;
    parameters = parameters1;

}

Predicate::Predicate() {

}
