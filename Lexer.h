#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Automaton.h"
#include "MatcherAutomaton.h"
#include "IDAutomaton.h"
#include "CommentAutomaton.h"
#include "StringAutomaton.h"
using namespace std;

#ifndef UNTITLED_LEXER_H
#define UNTITLED_LEXER_H


class Lexer {
private:
    std::vector<Token*> tokens;
    std::vector<Automaton*> automata;
public:
    Lexer() {
        tokens =  vector<Token*>();
        automata =  vector<Automaton*>();

        automata.push_back(new MatcherAutomaton(",", COMMA));
        automata.push_back(new MatcherAutomaton(".", PERIOD));
        automata.push_back(new MatcherAutomaton("?", Q_MARK));
        automata.push_back(new MatcherAutomaton("(", LEFT_PAREN));
        automata.push_back(new MatcherAutomaton(")", RIGHT_PAREN));
        automata.push_back(new MatcherAutomaton(":", COLON));
        automata.push_back(new MatcherAutomaton(":-", COLON_DASH));
        automata.push_back(new MatcherAutomaton("*", MULTIPLY));
        automata.push_back(new MatcherAutomaton("+", ADD));
        automata.push_back(new MatcherAutomaton("Schemes", SCHEMES));
        automata.push_back(new MatcherAutomaton("Facts", FACTS));
        automata.push_back(new MatcherAutomaton("Rules", RULES));
        automata.push_back(new MatcherAutomaton("Queries", QUERIES));
        automata.push_back(new IDAutomaton(ID));
        automata.push_back(new StringAutomaton(STRING));
        automata.push_back(new CommentAutomaton(COMMENT));
        //UNDEFINED
        //EOF
    };
    void Run(string& inputString);
    string toString();
// Other needed methods here

    int removeWhitespace(string& input);

    vector<Token *> GetTokens();
};


#endif //UNTITLED_LEXER_H
