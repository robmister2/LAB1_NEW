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

Relation Relation::join(Relation relation2) {
    Relation relation = copy();
    relation.setHeader(header->join(relation2.getHeader()));

    set<Tuple>::iterator it1 = rows.begin();
    set<Tuple>::iterator it2 = relation2.rows.begin();
    vector<string> header1 = header->getAttributes();
    vector<string> header2 = relation2.header->getAttributes();

    vector<vector<unsigned int>> pairs;
    for (unsigned int i = 0; i < header1.size(); ++i){
        for (unsigned int j = 0; j < header2.size(); ++j){
            if(header1.at(i) == header2.at(j)){
                vector<unsigned int> pair {(i) ,(j)};
                pairs.push_back(pair);
            }
        }
    }
    vector<int> indexes;
    bool inPairs;
    for (unsigned int i = 0; i < header2.size(); ++i){
        inPairs = false;
        for (unsigned int j = 0; j < pairs.size(); ++j){
            if(i == pairs.at(j).at(1)){
                inPairs = true;
            }
        }
        if(!inPairs){
            indexes.push_back(i);
        }
    }


    while(it1 != rows.end()){
        Tuple t1 = *it1;
        while(it2 != relation2.rows.end()){
            Tuple t2 = *it2;

            if(pairs.empty() || isJoinable(t1, t2, pairs)){
                Tuple tuple = combineTuples(t1, t2, indexes);
                relation.insertTuple(tuple);
            }

            ++it2;
        }
        it2 = relation2.rows.begin();
        ++it1;
    }

    return relation;
}

Relation Relation::unionize(Relation relation2) {
    Relation relation = copy();
    relation.rows = rows;
    set<Tuple>::iterator it = relation2.rows.begin();

    while(it != relation2.rows.end()){
        Tuple tuple = *it;
        relation.insertTuple(tuple);
        ++it;
    }
    return relation;
}


bool Relation::isJoinable(Tuple t1, Tuple t2, vector<vector<unsigned int>> pairs) {
    for (unsigned int i = 0; i < pairs.size(); ++i){
        if(t1.getValue(pairs.at(i).at(0)) != t2.getValue(pairs.at(i).at(1))) {
            return false;
        }
    }
    return true;
}

Tuple Relation::combineTuples(Tuple t1, Tuple t2, vector<int> indexes) {
    Tuple tuple = t1.copy();

    for (unsigned int i = 0; i < indexes.size(); ++i){
        tuple.insertValue(t2.getValue(indexes.at(i)));
    }

    return tuple;
}

string Relation::newTupleToString() {
    if(header->isEmpty()){
        return "";
    }
    string output;
    vector<string> headerValues = header->getAttributes();

    set<Tuple>::iterator it = newTuples.begin();

    while(it != newTuples.end()){
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

