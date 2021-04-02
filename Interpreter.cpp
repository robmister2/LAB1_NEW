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
    vector<Rule *> rules = program->getRules();
    int count = 0;
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
    cout << "Rule Evaluation" << endl;
    bool hasChanged = true;
    while(hasChanged) {
        count += 1;
        hasChanged = false;
        for (unsigned int i = 0; i < rules.size(); ++i) {
            vector<Relation> relations;
            Rule* rule = rules.at(i);
            //for each predicate p on the right side of the colon dash
            vector<Predicate *> predicates = rule->getPreds();
            //evaluate p as you would query - will return new relation r
            for (unsigned int j = 0; j < predicates.size(); ++j) {
                Predicate* predicate = predicates.at(j);
                Relation relation = evaluatePredicate(predicate);
                //store relation r in a collection
                relations.push_back(relation);

            }
            Relation joinRelation = relations.at(0);
            for (unsigned int j = 1; j < relations.size(); ++j) {
                //for each new relation r
                //join together to create the final relation f1
                joinRelation = joinRelation.join(relations.at(j));
            }
            //project the columns of the head predicate on f1
            vector<int> projectIndicies;
            vector<Parameter *> parameters = rule->getHead()->getParameters();
            vector<string> parameters2 = joinRelation.getHeader()->getAttributes();
            for (unsigned int j = 0; j < parameters.size(); ++j){
                if(!parameters.at(j)->getIsConstant()){
                    bool match = false;
                    for (unsigned int k = 0; k < projectIndicies.size(); ++k){
                        if(parameters2.at(projectIndicies.at(k)) == parameters.at(j)->toString()){
                            match = true;
                        }
                    }
                    if (!match) {
                        for (unsigned int k = 0; k < parameters2.size(); ++k){
                            if(parameters2.at(k) == parameters.at(j)->toString()){
                                projectIndicies.push_back(k);
                                break;
                            }
                        }
                    }
                }
            }

            //this creates a new relation f2
            Relation f2 = joinRelation.project(projectIndicies);
            string name = rule->getHead()->getName();
            //let Rdb be the relation in the database that matches the head predicate
            Relation rdb = database->getRelation(name);
            //rename each attribute in f2 to match Rdb
            //this creates a new relation f3
            Relation f3 = f2.rename(rdb.getHeader()->getAttributes());
            //f3 will now be union compatible with Rdb
            //union f3 with the Rdb
            Relation f4 = rdb.unionize(f3);
            //update Rdb in the database with the new relation
            database->replaceRelation(name, f4);
            cout << rule->toString() << endl;
            if(rdb.getRowCount() != f4.getRowCount()){
                hasChanged = true;
                cout << f4.newTupleToString();
            }
        }
    }


    //for each query ‘q’
    cout << endl;
    cout << "Schemes populated after "<< count << " passes through the Rules." << endl << endl;
    cout << "Query Evaluation" << endl;
    for (unsigned int i = 0; i < queries.size(); ++i) {
        Relation relation = evaluatePredicate(queries.at(i));

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

Relation Interpreter::evaluatePredicate(Predicate* query) {
    //get the relation ‘r’ with the same name as the query ‘q’
    Relation relation = database->getRelation(query->getName());
    vector <Parameter*> parameters = query->getParameters();

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
    vector<int> projectIndicies = getProjectIndicies(parameters);

    relation = relation.project(projectIndicies);

    //rename to match the names of variables in ‘q’
    vector<string> renames;
    for(unsigned int j = 0; j < projectIndicies.size(); ++j){
        renames.push_back(parameters.at(projectIndicies.at(j))->toString());
    }
    relation = relation.rename(renames);
    return relation;
}

string Interpreter::toString() {
    string outputString;
    return outputString;
}

vector<int> Interpreter::getProjectIndicies(vector<Parameter *> parameters) {
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
    return projectIndicies;
}

