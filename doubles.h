#ifndef DOUBLES_H
#define DOUBLES_H

#include <string>
#include "token.h"

class doubles: public token {
private:
    std::string _type;
    double _value;
public:
    doubles();
    explicit doubles(std::string thing);                //pass in data
    std::string what_type() const {return _type;}       //self evident
    double get_value() const {return _value;}           //seriously? the entire code is literally right there
};

#endif // DOUBLES_H
