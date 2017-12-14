#ifndef RPN_H
#define RPN_H

#include "queue.h"
#include "stack.h"
#include "doubles.h"
#include "binary_fcns.h"
#include "unary_fcns.h"
#include "variable.h"
#include "token.h"

class rpn
{
public:
    static double calculate(const queue<token*>& input, double vars = 0);   //it calculates and returns a double
};

#endif // RPN_H
