
#include <string>
#ifndef LAB1_NEW_RULE_H
#define LAB1_NEW_RULE_H
#include "Predicate.h"
#include <vector>
using namespace std;


class Rule {
private:
    Predicate* headPredicate;
    vector<Predicate*> predicates;

    public:
    string toString();
    Rule(Predicate* headpred1, vector<Predicate*> preds1);

};


#endif //LAB1_NEW_RULE_H
