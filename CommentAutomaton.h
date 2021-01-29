#include "Automaton.h"

#ifndef LAB1_NEW_COMMENTAMATON_H
#define LAB1_NEW_COMMENTAMATON_H


class CommentAutomaton:
            public Automaton
    {
    private:

    public:
        CommentAutomaton(TokenType tokenType);

        int Start (const string& input);



    };

#endif //LAB1_NEW_COMMENTAMATON_H
