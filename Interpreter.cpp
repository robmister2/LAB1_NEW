//
// Created by Rob on 3/11/2021.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram *datalogProgram, Database *database1) {
    program = datalogProgram;
    database = database1;
}

void Interpreter::run() {
    vector<Predicate *> schemes = program->getSchemes();
    vector<Predicate *> facts = program->getFacts();
    vector<Predicate *> queries = program->getQueries();
   // vector<Relation> relations;

    for (unsigned int i = 0; i < schemes.size(); ++i) {
        string schemeName = schemes.at(i)->getName();
        Relation relation = Relation(schemes.at(i));
        database->insertScheme(schemeName, relation);

    }

    for (unsigned int i = 0; i < facts.size(); ++i) {
        string factName = facts.at(i)->getName(); //find matching name in map
        Tuple newTuple = Tuple(facts.at(i));
        database->insertFact(factName, newTuple);
    }
    //for each query ‘q’
    for (unsigned int i = 0; i < queries.size(); ++i) {
        //get the relation ‘r’ with the same name as the query ‘q’
        Relation relation = database->getRelation(queries.at(i)->getName());
        vector <Parameter*> parameters = queries.at(i)->getParameters();

        //select for each constant in the query ‘q’
        for (unsigned int j = 0; j < parameters.size(); ++j){
            if(parameters.at(j)->getIsConstant()){
                relation = relation.selectByValue(j, parameters.at(j)->toString());
            }
        }
        //select for each pair of matching variables in ‘q’
        for (unsigned int j = 0; j < parameters.size() - 1; ++j){
            if(!parameters.at(j)->getIsConstant()){
                for (unsigned int k = j+1; k < parameters.size(); ++k){
                    if(parameters.at(j)->toString() == parameters.at(k)->toString()){
                        relation = relation.selectByMatching(j,k);
                    }
                }
            }
        }
        //project using the positions of the variables in ‘q’
        vector<int> projectIndicies;
        for (unsigned int j = 0; j < parameters.size(); ++j){
            if(!parameters.at(j)->getIsConstant()){
                bool match = false;
                for (unsigned int k = 0; k < projectIndicies.size(); ++k){
                    if(parameters.at(projectIndicies.at(k))->toString() == parameters.at(j)->toString()){
                        match = true;
                    }
                }
                if (!match) {
                    projectIndicies.push_back(j);
                }
            }
        }
        relation = relation.project(projectIndicies);

        //rename to match the names of variables in ‘q’
        vector<string> renames;
        for(unsigned int j = 0; j < projectIndicies.size(); ++j){
            renames.push_back(parameters.at(projectIndicies.at(j))->toString());
        }
        relation = relation.rename(renames);

        //print the resulting relation
        cout << queries.at(i)->toString();
        cout << "?";
        if(relation.getRowCount() == 0){
            cout << " No" << endl;
        }
        else{
            cout << " Yes(" << relation.getRowCount() << ")" << endl;
            cout << relation.toString();
        }

        //relations.push_back(relation);
    }

}

Relation Interpreter::evaluatePredicate(Predicate query) {
    return Relation();
}

string Interpreter::toString() {
    string outputString;
    return outputString;
}

