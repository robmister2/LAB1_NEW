
#ifndef LAB1_NEW_PARAMETER_H
#define LAB1_NEW_PARAMETER_H
#include <string>
using namespace std;


    class Parameter {
protected:
        bool isConstant;
public:
    virtual string toString();
    bool getIsConstant(){
        return isConstant;
    }

};


#endif //LAB1_NEW_PARAMETER_H
