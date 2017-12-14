#ifndef UNARY_FCNS_H
#define UNARY_FCNS_H

#include "token.h"

class unary_fcns: public token {
private:
    std::string _operator;
public:
    unary_fcns();
    explicit unary_fcns(std::string input);
    std::string what_type() const {return "unary";}
    int precedence() const {return 3;}
    std::string get_value() const {return _operator;}
    double operate(double right);
};

#endif // UNARY_FCNS_H
