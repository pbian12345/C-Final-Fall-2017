
#include "binary_fcns.h"
#include <cmath>

binary_fcns::binary_fcns() {
    _operator = "";
    _precedence = NULL;
}
binary_fcns::binary_fcns(std::string thing):token(thing, "binary") {
    //saves data and precedence
    //passes info back to parent class
    _operator = thing;
    if (thing == "+"){
        _precedence = 1;
    }
    else if(thing == "-"){
        _precedence = 1;
    }
    else if(thing == "*"){
        _precedence = 2;
    }
    else if(thing == "/"){
        _precedence = 2;
    }
    else if(thing == "^"){
        _precedence = 3;
    }
}
double binary_fcns::operate(double left, double right) {
    if (_operator == "+"){
        return left + right;
    }
    else if(_operator == "-"){
        return left - right;
    }
    else if(_operator == "*"){
        return left * right;
    }
    else if(_operator == "/"){
        return left / right;
    }
    else if(_operator == "^"){
        return pow(left, right);
    }
}
