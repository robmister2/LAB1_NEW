//
// Created by Rob on 3/11/2021.
//

#ifndef LAB1_NEW_HEADER_H
#define LAB1_NEW_HEADER_H
#include "Predicate.h"
#include <vector>
#include <string>
using namespace std;


class Header {
private:
    vector<string> attributes;
public:
    Header();
    Header(Predicate *schemes);
    Header* project (vector<int> indicies);
    Header* rename (vector<string> renames);
    vector<string> getAttributes(){
        return attributes;
    }
    bool isEmpty(){
        return attributes.empty();
    }


};


#endif //LAB1_NEW_HEADER_H
