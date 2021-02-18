
#ifndef LAB1_NEW_PARSER_H
#define LAB1_NEW_PARSER_H
#include "Token.h"
#include "vector"
#include "DatalogProgram.h"
#include "PlainParameter.h"
#include "Expression.h"
#include "Predicate.h"
#include "Rule.h"


class Parser {
private:
    DatalogProgram* stream;


public:

    Parser();
    DatalogProgram* getDatalogProgram ();

    void parse(vector<Token*> &tokens);
    void datalogProgram(vector<Token*> &tokens);

   void schemeList(vector<Token*> &tokens);
   void factList(vector<Token*> &tokens);
   void  ruleList(vector<Token*> &tokens);
   void  queryList(vector<Token*> &tokens);

   Predicate * scheme(vector<Token*> &tokens);
   Predicate * fact(vector<Token*> &tokens);
   Rule * rule(vector<Token*> &tokens);
   Predicate * query(vector<Token*> &tokens);

   Predicate * headPredicate(vector<Token*> &tokens);
   Predicate * predicate(vector<Token*> &tokens);

   void  predicateList(vector<Token*> &tokens, vector<Predicate*> &predicates);
   void  parameterList(vector<Token*> &tokens, vector<Parameter*> &parameters);
   void  stringList(vector<Token*> &tokens, vector<Parameter*> &strings);
   void idList(vector<Token *> &tokens, vector<Parameter*> &ids);

   Parameter * parameter(vector<Token*> &tokens);
   Expression * expression(vector<Token*> &tokens);
   TokenType operatorParse(vector<Token*> &tokens);
   //TERMINALS

  void SCHEMESparse(vector<Token*> &tokens);
  void COLONparse(vector<Token*> &tokens);
  void FACTSparse(vector<Token*> &tokens);
  void RULESparse(vector<Token*> &tokens);
  void QUERIESparse(vector<Token*> &tokens);
  void END_OF_FILEparse(vector<Token*> &tokens);
  PlainParameter * IDparse(vector<Token*> &tokens);
  void LEFT_PARENparse(vector<Token*> &tokens);
  void RIGHT_PARENparse(vector<Token*> &tokens);
  PlainParameter * STRINGparse(vector<Token*> &tokens);
  void PERIODparse(vector<Token*> &tokens);
  void COLON_DASHparse(vector<Token*> &tokens);
  void Q_MARKparse(vector<Token*> &tokens);
  void COMMAparse(vector<Token*> &tokens);
  void ADDparse(vector<Token*> &tokens);
  void MULTIPLYparse(vector<Token*> &tokens);

};


#endif //LAB1_NEW_PARSER_H
