
#include "unary_fcns.h"
#include <cmath>

unary_fcns::unary_fcns() {
    _operator = "";
}
unary_fcns::unary_fcns(std::string input):token(input, "unary") {
    //saves data and precedence
    //passes info back to parent class
    _operator = input;
}
double unary_fcns::operate(double right) {
    if (_operator == "sin"){
        return sin(right);
    }
    else if(_operator == "cos"){
        return cos(right);
    }
    else if(_operator == "tan"){
        return tan(right);
    }
    else if(_operator == "csc"){
        return 1/(sin(right));
    }
    else if(_operator == "sec"){
        return 1/(cos(right));
    }
    else if(_operator == "cot"){
        return 1/(tan(right));
    }
    else if(_operator == "log"){
        return log10(right);
    }
    else if(_operator == "ln"){
        return log(right);
    }
}
