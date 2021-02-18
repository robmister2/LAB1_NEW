//
// Created by Rob on 2/18/2021.
//

#include "PlainParameter.h"

PlainParameter::PlainParameter(string name1) {
    name = name1;

}

string PlainParameter::getName() {
    return name;
}

string PlainParameter::toString() {
    return name;
}
