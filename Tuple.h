

#ifndef LAB1_NEW_TUPLE_H
#define LAB1_NEW_TUPLE_H
#include <vector>
#include <string>
#include "Predicate.h"

using namespace std;

class Tuple {
private:
    vector<string> values;
public:
    Tuple();
    bool operator< (const Tuple & other) const {
         for (unsigned int i = 0; i < values.size(); ++i){
             if(values.at(i).compare(other.values.at(i)) > 0){ //if one word is longer than another, or alphabetical //FIXME not correctly inserting into datalog program
                 return false;
             }
         }
         return true;
    }
    string getValue(int i){
        return values.at(i);
    }

    Tuple(Predicate *fact);

    Tuple project (vector<int> indicies);
};







#endif //LAB1_NEW_TUPLE_H
