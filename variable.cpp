
#include "variable.h"

variable::variable():token("x", "variable") {
    //saves data and precedence
    //passes info back to parent class
    _type = "variable";
}
double variable::plug_in(double right) {
    return right;
}
