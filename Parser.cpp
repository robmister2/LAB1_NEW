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
    scheme(tokens);
    schemeList(tokens);
    FACTSparse(tokens);
    COLONparse(tokens);
    factList(tokens);
    RULESparse(tokens);
    COLONparse(tokens);
    ruleList(tokens);
    QUERIESparse(tokens);
    COLONparse(tokens);
    query(tokens);
    queryList(tokens);
    END_OF_FILEparse(tokens);


}

void Parser::schemeList(vector<Token*> &tokens) {
    //schemeList	->	scheme schemeList | lambda
    if(tokens.front()->getTokenType() == ID){
        scheme(tokens);
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
        fact(tokens);
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
        rule(tokens);
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
        query(tokens);
        queryList(tokens);

    }
    else if (tokens.front()->getTokenType() == END_OF_FILE){

    }
    else{
        throw "bad";
    }


}

void Parser::scheme(vector<Token*> &tokens) {
    //scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
    if(tokens.front()->getTokenType() == ID){
      IDparse(tokens);
      LEFT_PARENparse(tokens);
      IDparse(tokens);
      idList(tokens);
      RIGHT_PARENparse(tokens);

    }
    else if (tokens.front()->getTokenType() == COLON){

    }
    else{
        throw "bad";
    }

}

void Parser::fact(vector<Token*> &tokens) {
    //fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    if(tokens.front()->getTokenType() == ID){
        IDparse(tokens);
        LEFT_PARENparse(tokens);
        STRINGparse(tokens);
        stringList(tokens);
        RIGHT_PARENparse(tokens);
        PERIODparse(tokens);
    }
    else if (tokens.front()->getTokenType() == RULES){

    }
    else{
        throw "bad";
    }

}

void Parser::rule(vector<Token*> &tokens) {
    //rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
    if(tokens.front()->getTokenType() == ID){
    headPredicate(tokens);
    COLON_DASHparse(tokens);
    predicate(tokens);
    predicateList(tokens);
    PERIODparse(tokens);
}
    else{
        throw "bad";
    }
}

void Parser::query(vector<Token*> &tokens) {
    //query	        ->      predicate Q_MARK
    if(tokens.front()->getTokenType() == ID){
        predicate(tokens);
        Q_MARKparse(tokens);
    }
    else{
        throw "bad";
    }

}

void Parser::headPredicate(vector<Token*> &tokens) {
   // headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    if(tokens.front()->getTokenType() == ID){
        IDparse(tokens);
        LEFT_PARENparse(tokens);
        IDparse(tokens);
        idList(tokens);
        RIGHT_PARENparse(tokens);
    }
    else{
        throw "bad";
    }


}

void Parser::predicate(vector<Token*> &tokens) {
    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    if(tokens.front()->getTokenType() == ID){
        IDparse(tokens);
        LEFT_PARENparse(tokens);
        parameter(tokens);
        parameterList(tokens);
        RIGHT_PARENparse(tokens);
    }
    else{
        throw "bad";
    }

}

void Parser::predicateList(vector<Token*> &tokens) {
    //predicateList	->	COMMA predicate predicateList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        predicate(tokens);
        predicateList(tokens);
    }
    else if(tokens.front()->getTokenType() == PERIOD){
    }
    else{
        throw "bad";
    }

}

void Parser::parameterList(vector<Token*> &tokens) {
    //parameterList	-> 	COMMA parameter parameterList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        parameter(tokens);
        parameterList(tokens);
    }
    else if(tokens.front()->getTokenType() == RIGHT_PAREN){
    }
    else{
        throw "bad";
    }

}

void Parser::stringList(vector<Token*> &tokens) {
    //stringList	-> 	COMMA STRING stringList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        STRINGparse(tokens);
        stringList(tokens);
    }
    else if(tokens.front()->getTokenType() == RIGHT_PAREN){
    }
    else{
        throw "bad";
    }

}

void Parser::idList(vector<Token*> &tokens) {
    //idList  	-> 	COMMA ID idList | lambda
    if(tokens.front()->getTokenType() == COMMA){
        COMMAparse(tokens);
        IDparse(tokens);
        idList(tokens);
    }
    else if(tokens.front()->getTokenType() == RIGHT_PAREN){
    }
    else{
        throw "bad";
    }

}

void Parser::parameter(vector<Token*> &tokens) {
    //parameter	->	STRING | ID | expression
    if(tokens.front()->getTokenType() == STRING){
        STRINGparse(tokens);
    }
    else if(tokens.front()->getTokenType() == ID){
        IDparse(tokens);
    }
    else if(tokens.front()->getTokenType() == LEFT_PAREN){
        expression(tokens);
    }
    else{
        throw "bad";
    }

}

void Parser::expression(vector<Token*> &tokens) {
    //expression	->	LEFT_PAREN parameter operator parameter RIGHT_PAREN
    if(tokens.front()->getTokenType() == LEFT_PAREN){
        LEFT_PARENparse(tokens);
        parameter(tokens);
        operatorParse(tokens);
        parameter(tokens);
        RIGHT_PARENparse(tokens);
    }
    else{
        throw "bad";
    }

}

void Parser::operatorParse(vector<Token*> &tokens) {
    //operator	->	ADD | MULTIPLY
    if(tokens.front()->getTokenType() == ADD){
        ADDparse(tokens);
    }
    if(tokens.front()->getTokenType() == MULTIPLY){
        MULTIPLYparse(tokens);
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

void Parser::IDparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == ID){
        tokens.erase(tokens.begin());
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

void Parser::STRINGparse(vector<Token *> &tokens) {
    if(tokens.front()->getTokenType() == STRING){
        tokens.erase(tokens.begin());
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
