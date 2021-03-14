
#include <set>
#include <vector>
#include "Parameter.h"
#include "Parser.h"
#include "Predicate.h"
#include "Rule.h"
#ifndef LAB1_NEW_DATALOGPROGRAM_H
#define LAB1_NEW_DATALOGPROGRAM_H
using namespace std;



class DatalogProgram{
private:
    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<Predicate*> queries;
    vector<Rule*> rules;
    set<string> domains;

    public:
    void insertSchemes(Predicate *scheme);
    void insertFacts(Predicate *fact);
    void insertQueries(Predicate *query);
    void insertRules(Rule *rule);
    void insertDomain(string domain);
    string toString();

    vector<Predicate*> getSchemes(){
        return schemes;
    }
    vector<Predicate*> getFacts(){
        return facts;
    }
    vector<Predicate*> getQueries(){
        return queries;
    }

};


#endif //LAB1_NEW_DATALOGPROGRAM_H
