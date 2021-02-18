//
// Created by Rob on 2/18/2021.
//

#include "DatalogProgram.h"


void DatalogProgram::insertSchemes(Predicate *scheme) {
    schemes.push_back(scheme);

}

void DatalogProgram::insertFacts(Predicate *fact) {
    facts.push_back(fact);

}

void DatalogProgram::insertQueries(Predicate *query) {
    queries.push_back(query);

}

void DatalogProgram::insertRules(Rule *rule) {
    rules.push_back(rule);

}
void DatalogProgram::insertDomain(string domain) {
    domains.insert(domain);
}

string DatalogProgram::toString() {
    string output;
    output += "Schemes(";
    output += to_string(schemes.size());
    output += "):\n";
    for (unsigned int i = 0; i < schemes.size(); ++i){
        output += "  ";
        output += schemes.at(i)->toString();
        output += "\n";
    }

    output += "Facts(";
    output += to_string(facts.size());
    output += "):\n";
    for (unsigned int i = 0; i < facts.size(); ++i){
        output += "  ";
        output += facts.at(i)->toString();
        output += ".\n";
    }

    output += "Rules(";
    output += to_string(rules.size());
    output += "):\n";
    for (unsigned int i = 0; i < rules.size(); ++i){
        output += "  ";
        output += rules.at(i)->toString();
        output += "\n";
    }

    output += "Queries(";
    output += to_string(queries.size());
    output += "):\n";
    for (unsigned int i = 0; i < queries.size(); ++i){
        output += "  ";
        output += queries.at(i)->toString();
        output += "?";
        output += "\n";
    }
    output += "Domain(";
    output += to_string(domains.size());
    output += "):\n";
    set<string>::iterator it = domains.begin();
    while(it != domains.end()){
        output += "  ";
        output += *it;
        output += "\n";
        ++it;
    }

    return output;

}
