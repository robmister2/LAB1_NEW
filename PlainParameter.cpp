//
// Created by Rob on 2/18/2021.
//

#include "PlainParameter.h"

PlainParameter::PlainParameter(string name1, bool isConstant1) {
    name = name1;
    isConstant = isConstant1;
}

string PlainParameter::getName() {
    return name;
}

string PlainParameter::toString() {
    return name;
}
