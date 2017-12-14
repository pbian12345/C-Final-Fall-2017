#include "special.h"

special::special(){
    _value = NULL;
}
special::special(string thing):token(thing, "special"){
    //saves data and precedence
    //passes info back to parent class
    if (thing == "("){
        _value = '(';
    }
    else if(thing == ")"){
        _value = ')';
    }
}
