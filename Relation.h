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
public:
    Relation();
    Relation(Predicate* scheme);
   Relation selectByValue (unsigned int index, string value);

   Relation selectByMatching (unsigned int index1, unsigned int index2);

   Relation project (vector<int> indicies);

   Relation rename (vector<string> renames);

   string toString();

   Relation copy();

   int getRowCount(){
       return rows.size();
   }

   void setName(string name1){
       name = name1;
   }
   void setHeader(Header* header1){
       header = header1;
   }

   void insertTuple (Tuple newTuple){
       rows.insert(newTuple);
   }


};


#endif //LAB1_NEW_RELATION_H
