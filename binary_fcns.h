#ifndef BINARY_FCNS_H
#define BINARY_FCNS_H

#include <string>
#include "token.h"

class binary_fcns: public token {
private:
    string _operator;
    int _precedence;
public:
    binary_fcns();
    explicit binary_fcns(std::string thing);                //passing in data
    std::string what_type() const {return "binary";}        //returns type
    int precedence() const {return _precedence;}            //returns precedence of operator
    string get_value() const {return _operator;}            //returns current value of operator
    double operate(double left, double right);              //used in rpn to calculate
};

#endif // BINARY_FCNS_H

//needs a precedence fcn

//shunting yard:
//operators with greater precedence go to top of stack
//so if stack from bottom to top is *, / then put in +
//so pop * and / into output Q, then put + into stack and continue
//open parentheses are ignored***************************************************************
//at close parentheses, pop all of stack until (and including) open parentheses and get rid of parentheses

//treat variables as fcns??
//also fcns have highest precedence
