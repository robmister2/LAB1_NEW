

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
        /*  for (unsigned int i = 0; i < values.size(); ++i){
              if(values.at(i).compare(other.values.at(i)) > 0){ //nope this is are not do be working
                  return false;
              }
          }
          return true; */
        return this->values < other.values;
    }

    string getValue(int i){

        return values.at(i);
    }

    Tuple(Predicate *fact);

    Tuple project (vector<int> indicies);

    Tuple copy();

    vector<string> getValues(){
        return values;
    }
    void insertValue(string value){
        values.push_back(value);
    }
};







#endif //LAB1_NEW_TUPLE_H
