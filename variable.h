#ifndef VARIABLE_H
#define VARIABLE_H

#include "token.h"

class variable: public token {
private:
    std::string _type;
public:
    variable();
    std::string what_type() const {return _type;}
    double plug_in(double right);
};

#endif // VARIABLE_H
