#include "Automaton.h"
#include <string>

using namespace std;

#ifndef UNTITLED_MATCHERAUTOMATON_H
#define UNTITLED_MATCHERAUTOMATON_H


class MatcherAutomaton:
        public Automaton
{
private:
string toMatch;

public:
    MatcherAutomaton(std::string toMatch, TokenType tokenType)
    {
        this->toMatch = toMatch;
        this->type = tokenType;
    };


int Start (const string& input);



};


#endif //UNTITLED_MATCHERAUTOMATON_H
