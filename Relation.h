//
// Created by Rob on 3/11/2021.
//

#ifndef LAB1_NEW_RELATION_H
#define LAB1_NEW_RELATION_H
#include "Tuple.h"
#include "Header.h"
#include "Predicate.h"
#include <vector>
#include <string>
#include <set>
using namespace std;

class Relation {
private:
    string name;
    Header* header;
    set<Tuple> rows;
    set<Tuple> newTuples;
public:
    Relation();
    Relation(Predicate* scheme);
   Relation selectByValue (unsigned int index, string value);

   Relation selectByMatching (unsigned int index1, unsigned int index2);

   Relation project (vector<int> indicies);

   Relation rename (vector<string> renames);

   Relation join (Relation relation2);

   Relation unionize (Relation relation2);

   bool isJoinable(Tuple t1, Tuple t2, vector<vector<unsigned int>> pairs);

   Tuple combineTuples(Tuple t1, Tuple t2, vector<int> indexes);

   string toString();

   Relation copy();

   int getRowCount(){
       return rows.size();
   }
   set<Tuple> getRows(){
       return rows;
   }

   void setName(string name1){
       name = name1;
   }
   string getName(){
       return name;
   }
   void setHeader(Header* header1){
       header = header1;
   }

   void insertTuple (Tuple newTuple){
       unsigned int rowsize = rows.size();
       rows.insert(newTuple);
       if(rows.size() != rowsize){
           newTuples.insert(newTuple);
       }
   }
   string newTupleToString();

   Header* getHeader(){
       return header;
   }


};


#endif //LAB1_NEW_RELATION_H
