//
// Created by Rob on 3/11/2021.
//

#include "Header.h"

Header::Header() {

}

Header::Header(Predicate *schemes) {
    vector<Parameter*> parameters = schemes->getParameters();
    for (unsigned int i = 0; i < parameters.size(); ++i){
        attributes.push_back(parameters.at(i)->toString());
    }
}

Header* Header::project(vector<int> indicies) {
    Header* header = new Header;
    for(unsigned int i = 0; i < indicies.size(); ++i){
        header->attributes.push_back(attributes.at(indicies.at(i)));
    }
    return header;
}

Header *Header::rename(vector<string> renames) {
    Header* header = new Header;
    header->attributes = renames;
    return header;
}

Header *Header::join(Header* header2) {
    Header* header = new Header;
    header->attributes = attributes;
    bool containName;
    vector<string> names = header2->attributes;

    for(unsigned int i = 0; i < names.size(); i++){
        containName = false; //HARD RESET
        for (unsigned int j = 0; j < header->attributes.size(); j++){
            if (header->attributes.at(j) == names.at(i)){
                containName = true;
            }
        }
        if (!containName) {
            header->attributes.push_back(names.at(i));
        }
    }
    return header;
}
