
#ifndef LAB1_NEW_PLAINPARAMETER_H
#define LAB1_NEW_PLAINPARAMETER_H
#include "Parameter.h"
#include <vector>
using namespace std;

class PlainParameter:
        public Parameter{
private:
    string name;
public:
    PlainParameter(string name1);
    string getName();

    string toString();

};


#endif //LAB1_NEW_PLAINPARAMETER_H
