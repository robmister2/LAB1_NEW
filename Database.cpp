//
// Created by Rob on 3/11/2021.
//

#include "Database.h"

Database::Database() {

}


void Database::insertScheme(string name, Relation relation) {

    relations.insert(pair<string, Relation>(name, relation));
}

void Database::insertFact(string name, Tuple tuple) {
    relations.at(name).insertTuple(tuple);

}

void Database::insertRule(string name, Tuple tuple) {
    relations.at(name).insertTuple(tuple);

}

void Database::replaceRelation(string name, Relation relation) {
    relations[name] = relation;

}

