//
// Created by Rob on 2/17/2021.
//

#include "Parser.h"

void Parser::parse(vector<Token*> &tokens) {
    datalogProgram(tokens);
}

void Parser::datalogProgram(vector<Token*> &tokens) {
    //datalogProgram	->	SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF

    SCHEMESparse(tokens);
    COLONparse(tokens);
    stream->insertSchemes(scheme(tokens));
    schemeList(tokens);
    FACTSparse(tokens);
    COLONparse(tokens);
    factList(tokens);
    RULESparse(tokens);
    COLONparse(tokens);
    ruleList(tokens);
    QUERIESparse(tokens);
    COLONparse(tokens);
    stream->insertQueries(query(tokens));
    queryList(tokens);
    END_OF_FILEparse(tokens);


}

void Parser::schemeList(vector<Token*> &tokens) {
    //schemeList	->	scheme schemeList | lambda
    if(tokens.front()->getTokenType() == ID){
        stream->insertSchemes(scheme(tokens));
        schemeList(tokens);
    }
    else if (tokens.front()->getTokenType() == FACTS){

    }
    else{
        throw "bad schemelist";
    }

}

void Parser::factList(vector<Token*> &tokens) {
    //factList	->	fact factList | lambda
    if(tokens.front()->getTokenType() == ID){
        stream->insertFacts(fact(tokens));
        factList(tokens);
    }
    else if (tokens.front()->getTokenType() == RULES){

    }
    else{
        throw "bad";
    }

}

void Parser::ruleList(vector<Token*> &tokens) {
    //ruleList	->	rule ruleList | lambda
    if(tokens.front()->getTokenType() == ID){
        stream->insertRules(rule(tokens));
        ruleList(tokens);

    }
    else if (tokens.front()->getTokenType() == QUERIES){

    }
    else{
        throw "bad";
    }

}

void Parser::queryList(vector<Token*> &tokens) {
    //queryList	->	query queryList | lambda
    if(tokens.front()->getTokenType() == ID){
        stream->insertQueries(query(tokens));
        queryList(tokens);

    }
    else if (tokens.front()->getTokenType() == END_OF_FILE){

    }
    else{
        throw "bad";
    }


}

Predicate* Parser::scheme(vector<Token*> &tokens) {
    //scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
    if(tokens.front()->getTokenType() == ID){
        vector<Parameter*> parameters;
      string name = IDparse(tokens)->getName();

      LEFT_PARENparse(tokens);
      parameters.push_back(IDparse(tokens));
      idList(tokens ,parameters);
      RIGHT_PARENparse(tokens);

      return(new Predicate(name, parameters));

    }
    else{
        throw "bad";
    }

}

Predicate* Parser::fact(vector<Token*> &tokens) {
    //fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    if(tokens.front()->getTokenType() == ID){
        vector<Parameter*> parameters;

        string name = IDparse(tokens)->getName();
        LEFT_PARENparse(tokens);
        parameters.push_back(STRINGparse(tokens));
        stringList(tokens, parameters);
        RIGHT_PARENparse(tokens);
        PERIODparse(tokens);
        for(unsigned int i = 0; i < parameters.size(); ++i){    //CREATING DOMAIN VECTOR
            stream->insertDomain(parameters.at(i)->toString());
        }

        return (new Predicate(name, parameters));
    }
    else{
        throw "bad";
    }

}

Rule* Parser::rule(vector<Token*> &tokens) {
    //rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
    if(tokens.front()->getTokenType() == ID){
    vector<Predicate*> predicates;

    Predicate* head = headPredicate(tokens);
    COLON_DASHparse(tokens);
    predicates.push_back(predicate(tokens));
    predicateList(tokens,predicates);
    PERIODparse(tokens);

    return(new Rule(head, predicates));
}
    else{
        throw "bad";
    }
}

Predicate* Parser::query(vector<Token*> &tokens) {
    //query	        ->      predicate Q_MARK
    if(tokens.front()->getTokenType() == ID){
        Predicate* pred = predicate(tokens);
        Q_MARKparse(tokens);
        return pred;
    }
    else{
        throw "bad";
    }

}

Predicate* Parser::headPredicate(vector<Token*> &tokens) {
   // headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    if(tokens.front()->getTokenType() == ID){
         vector<Parameter*> parameters;
        string name = IDparse(tokens)->getName();

        LEFT_PARENparse(tokens);
        parameters.push_back(IDparse(tokens));
        idList(tokens, parameters);
        RIGHT_PARENparse(tokens);

        return (new Predicate(name, parameters));
    }
    else{
        throw "bad";
    }


}

Predicate* Parser::predicate(vector<Token*> &tokens) {
    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    if(tokens.front()->getTokenType() == ID){
        vector<Parameter*> parameters;
        string name = IDparse(tokens)->getName();

        LEFT_PARENparse(tokens);
        parameters.push_back(parameter(tokens));
        parameterList(tokens, parameters);
        RIGHT_PARENparse(tokens);

        return(new Predicate(name, parameters));
    }
    else{
        throw "bad";
    }

}

void Parser::predicateList(vector<Token*> &tokens, vector<Predicate*>&predicates) {
    //predicateList	->	COMMA predicate predicateList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        predicates.push_back(predicate(tokens));
        predicateList(tokens, predicates);
    }
    else if(tokens.front()->getTokenType() == PERIOD){
    }
    else{
        throw "bad";
    }

}

void Parser::parameterList(vector<Token*> &tokens, vector<Parameter*> &parameters) {
    //parameterList	-> 	COMMA parameter parameterList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        parameters.push_back(parameter(tokens));
        parameterList(tokens, parameters);
    }
    else if(tokens.front()->getTokenType() == RIGHT_PAREN){
    }
    else{
        throw "bad";
    }

}

void Parser::stringList(vector<Token*> &tokens, vector<Parameter*> &strings) {
    //stringList	-> 	COMMA STRING stringList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        strings.push_back(STRINGparse(tokens));
        stringList(tokens, strings);
    }
    else if(tokens.front()->getTokenType() == RIGHT_PAREN){
    }
    else{
        throw "bad";
    }

}

void Parser::idList(vector<Token*> &tokens, vector<Parameter*> &ids) {
    //idList  	-> 	COMMA ID idList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        ids.push_back(IDparse(tokens));
        idList(tokens, ids);
    }
    else if(tokens.front()->getTokenType() == RIGHT_PAREN){
    }
    else{
        throw "bad";
    }

}

Parameter* Parser::parameter(vector<Token*> &tokens) {
    //parameter	->	STRING | ID | expression
    if(tokens.front()->getTokenType() == STRING){
        return STRINGparse(tokens);
    }
    else if(tokens.front()->getTokenType() == ID){
        return IDparse(tokens);
    }
    else if(tokens.front()->getTokenType() == LEFT_PAREN){
        return expression(tokens);
    }
    else{
        throw "bad";
    }

}

Expression* Parser::expression(vector<Token*> &tokens) {
    //expression	->	LEFT_PAREN parameter operator parameter RIGHT_PAREN
    if(tokens.front()->getTokenType() == LEFT_PAREN){
        LEFT_PARENparse(tokens);
       Parameter* parameter1 = parameter(tokens);
       TokenType op =  operatorParse(tokens);
       Parameter* parameter2 = parameter(tokens);
        RIGHT_PARENparse(tokens);

        return(new Expression(parameter1, op, parameter2));
    }
    else{
        throw "bad";
    }

}

TokenType Parser::operatorParse(vector<Token*> &tokens) {
    //operator	->	ADD | MULTIPLY
    if(tokens.front()->getTokenType() == ADD){
        ADDparse(tokens);
        return ADD;
    }
    if(tokens.front()->getTokenType() == MULTIPLY){
        MULTIPLYparse(tokens);
        return MULTIPLY;
    }
    else{
        throw "bad";
    }

}

void Parser::SCHEMESparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == SCHEMES){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad";
    }

}

void Parser::COLONparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == COLON){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad";
    }

}

void Parser::FACTSparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == FACTS){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad";
    }

}

void Parser::RULESparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == RULES){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad";
    }

}

void Parser::QUERIESparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == QUERIES){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad";
    }

}

void Parser::END_OF_FILEparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == END_OF_FILE){ //FIXME end of file will no way work the first time
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad";
    }

}

PlainParameter * Parser::IDparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == ID){
       PlainParameter *name = new PlainParameter(tokens.front()->getTokenInput(), false);
        tokens.erase(tokens.begin());
        return name;

    }
    else{
        throw "bad id";
    }

}

void Parser::LEFT_PARENparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == LEFT_PAREN){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad left paren";
    }

}

void Parser::RIGHT_PARENparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == RIGHT_PAREN){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad right paren";
    }

}

PlainParameter* Parser::STRINGparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == STRING){
        PlainParameter *name = new PlainParameter(tokens.front()->getTokenInput(), true);
        tokens.erase(tokens.begin());
        return name;
    }
    else{
        throw "bad string";
    }

}

void Parser::PERIODparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == PERIOD){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad period";
    }

}

void Parser::COLON_DASHparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == COLON_DASH){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad colon_dash";
    }

}

void Parser::Q_MARKparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == Q_MARK){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad question mark";
    }

}

void Parser::COMMAparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == COMMA){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad comma";
    }

}

void Parser::ADDparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == ADD){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad add";
    }

}

void Parser::MULTIPLYparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == MULTIPLY){
        tokens.erase(tokens.begin());
    }
    else{
        throw "bad multiply";
    }

}

Parser::Parser(){
    stream = new DatalogProgram;

}

DatalogProgram* Parser::getDatalogProgram() {
    return stream;
}


