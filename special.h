#ifndef SPECIAL_H
#define SPECIAL_H

#include "token.h"

class special: public token{
private:
    char _value;
public:
    special();
    special(std::string thing);
    std::string what_type() const {return "special";}
    char get_value() const {return _value;}
};

#endif // SPECIAL_H
