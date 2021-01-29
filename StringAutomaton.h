#include "Automaton.h"

#ifndef LAB1_NEW_STRINGAUTOMATON_H
#define LAB1_NEW_STRINGAUTOMATON_H


class StringAutomaton:
        public Automaton
{
private:

public:
    StringAutomaton(TokenType tokenType);

    int Start (const string& input);



};

#endif //LAB1_NEW_STRINGAUTOMATON_H
