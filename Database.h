//
// Created by Rob on 3/11/2021.
//

#ifndef LAB1_NEW_DATABASE_H
#define LAB1_NEW_DATABASE_H
#include "Relation.h"
#include "DatalogProgram.h"
#include <vector>
#include <string>
#include <map>
using namespace std;


class Database {
private:
    map<string, Relation> relations;
public:
    Database ();
    void insertScheme(string name, Relation relation);
    void insertFact(string name, Tuple tuple);
    void insertRule(string name, Tuple tuple);
    void replaceRelation(string name, Relation relation);
    Relation getRelation(string name){
        return relations.at(name);
    }

};


#endif //LAB1_NEW_DATABASE_H
