
#include "doubles.h"

doubles::doubles() {
    _type = "double";
    _value = 0;
}
doubles::doubles(std::string thing):token(thing, "double") {
    //saves data and precedence
    //passes info back to parent class
    _type = "double";
    _value = strtod(thing.c_str(), NULL);
}
