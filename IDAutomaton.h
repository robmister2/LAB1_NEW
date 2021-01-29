#include "Automaton.h"

#ifndef LAB1_NEW_IDAUTOMATON_H
#define LAB1_NEW_IDAUTOMATON_H


class IDAutomaton:
    public Automaton
{
private:
public:
    IDAutomaton(TokenType tokenType);

    int Start (const string& input);

};


#endif //LAB1_NEW_IDAUTOMATON_H
