//
// Created by Rob on 3/11/2021.
//

#include "Relation.h"

Relation Relation::selectByValue(unsigned int index, string value) {
    Relation relation = copy();
    set<Tuple>::iterator it = rows.begin();
    while(it != rows.end()){
        Tuple tuple = *it;
        if(tuple.getValue(index) == value){
            relation.insertTuple(tuple);
        }
        ++it;
    }

    return relation;
}

Relation Relation::selectByMatching(unsigned int index1, unsigned int index2) {
    Relation relation = copy();
    set<Tuple>::iterator it = rows.begin();
    while(it != rows.end()){
        Tuple tuple = *it;
        if(tuple.getValue(index1) == tuple.getValue(index2)){
            relation.insertTuple(tuple);
        }
        ++it;
    }

    return relation;
}

Relation Relation::project(vector<int> indicies) {
    Relation relation = copy();
    set<Tuple>::iterator it = rows.begin();
    relation.setHeader(header->project(indicies));

    while(it != rows.end()){
        Tuple tuple = *it;
        relation.insertTuple(tuple.project(indicies));
        ++it;
    }
    return relation;
}

Relation Relation::rename(vector<string> renames) {
    Relation relation = copy();
    relation.rows = rows;
    relation.setHeader(header->rename(renames));
    return relation;
}

Relation::Relation() {

}

Relation::Relation(Predicate *scheme) {
    name = scheme->getName();
    header = new Header(scheme);

}

string Relation::toString() {
    if(header->isEmpty()){
        return "";
    }
    string output;
    vector<string> headerValues = header->getAttributes();

    set<Tuple>::iterator it = rows.begin();

    while(it != rows.end()){
        Tuple tuple = *it;
        output += "  ";
        for(unsigned int i = 0; i < headerValues.size(); ++i){
            output += headerValues.at(i);
            output += "=";
            output += tuple.getValue(i);
            if (i < headerValues.size()-1){
                output += ", ";
            }
        }
        output += "\n";
        ++it;
    }
 return output;
}

Relation Relation::copy() {
    Relation relation = Relation();
    relation.setName(name);
    relation.setHeader(header);
    return relation;
}

