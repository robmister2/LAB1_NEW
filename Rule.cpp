//
// Created by Rob on 2/18/2021.
//

#include "Rule.h"

string Rule::toString() {
    string output;
    output += headPredicate->toString();
    output += " :- ";
    for (unsigned int i = 0; i < predicates.size(); ++i){
        output += predicates.at(i)->toString();
        if (i + 1 != predicates.size()) {
            output += ",";
        }
    }
    output += ".";
    return output;
}

Rule::Rule(Predicate* headpred1, vector<Predicate *> preds1) {
    headPredicate=headpred1;
    predicates=preds1;

}
