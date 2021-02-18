
#ifndef LAB1_NEW_PARSER_H
#define LAB1_NEW_PARSER_H
#include "Token.h"
#include "vector"


class Parser {


public:
    void parse(vector<Token*> &tokens);
    void datalogProgram(vector<Token*> &tokens);

   void schemeList(vector<Token*> &tokens);
   void factList(vector<Token*> &tokens);
   void  ruleList(vector<Token*> &tokens);
   void  queryList(vector<Token*> &tokens);

   void  scheme(vector<Token*> &tokens);
   void  fact(vector<Token*> &tokens);
   void  rule(vector<Token*> &tokens);
   void  query(vector<Token*> &tokens);

   void  headPredicate(vector<Token*> &tokens);
   void  predicate(vector<Token*> &tokens);

   void  predicateList(vector<Token*> &tokens);
   void  parameterList(vector<Token*> &tokens);
   void  stringList(vector<Token*> &tokens);
   void  idList (vector<Token*> &tokens);

   void  parameter(vector<Token*> &tokens);
   void  expression(vector<Token*> &tokens);
   void  operatorParse(vector<Token*> &tokens);
   //TERMINALS

  void SCHEMESparse(vector<Token*> &tokens);
  void COLONparse(vector<Token*> &tokens);
  void FACTSparse(vector<Token*> &tokens);
  void RULESparse(vector<Token*> &tokens);
  void QUERIESparse(vector<Token*> &tokens);
  void END_OF_FILEparse(vector<Token*> &tokens);
  void IDparse(vector<Token*> &tokens);
  void LEFT_PARENparse(vector<Token*> &tokens);
  void RIGHT_PARENparse(vector<Token*> &tokens);
  void STRINGparse(vector<Token*> &tokens);
  void PERIODparse(vector<Token*> &tokens);
  void COLON_DASHparse(vector<Token*> &tokens);
  void Q_MARKparse(vector<Token*> &tokens);
  void COMMAparse(vector<Token*> &tokens);
  void ADDparse(vector<Token*> &tokens);
  void MULTIPLYparse(vector<Token*> &tokens);


};


#endif //LAB1_NEW_PARSER_H
