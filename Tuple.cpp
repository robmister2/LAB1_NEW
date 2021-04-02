//
// Created by Rob on 3/11/2021.
//

#include "Tuple.h"

Tuple::Tuple(Predicate *fact) {
    vector<Parameter*> parameters = fact->getParameters();
    for (unsigned int i = 0; i < parameters.size(); ++i){
        values.push_back(parameters.at(i)->toString());
    }
}

Tuple Tuple::project(vector<int> indicies) {
    Tuple tuple;
    for(unsigned int i = 0; i < indicies.size(); ++i){
        tuple.values.push_back(values.at(indicies.at(i)));
    }
    return tuple;
}

Tuple::Tuple() {

}

Tuple Tuple::copy() {
    Tuple tuple = Tuple();
    tuple.values = values;
    return tuple;
}
