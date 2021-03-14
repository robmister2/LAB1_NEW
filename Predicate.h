
#ifndef LAB1_NEW_PREDICATE_H
#define LAB1_NEW_PREDICATE_H
#include <string>
#include <vector>
#include "Parameter.h"
using namespace std;


class Predicate {
private:
    string name;
    vector<Parameter*> parameters;

public:
    Predicate();
    Predicate(string name1, vector<Parameter*> parameters1);
    string toString();
    string getName(){
        return name;
    }
    vector<Parameter*> getParameters(){
        return parameters;
    }

};


#endif //LAB1_NEW_PREDICATE_H
