#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "queue.h"
#include "stack.h"
#include "doubles.h"
#include "binary_fcns.h"
#include "unary_fcns.h"
#include "variable.h"
#include "token.h"

class shunting_yard
{
private:
    queue<token*> _infix;
    queue<token*> _postfix;
    stack<token*> _stack;
public:
    shunting_yard();
    shunting_yard(queue<token*> input);

    bool check_precedence(token* temp);         //recursive
    void sh_yrd();                              //shunt things
    queue<token*> get_postfix() const {return _postfix;}
};

#endif // SHUNTING_YARD_H
