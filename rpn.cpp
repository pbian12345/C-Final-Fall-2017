#include "rpn.h"

double rpn::calculate(const queue<token *>& input, double vars){
    queue<token*> postfix(input);
    stack<double> primary_stack;
    token* temp;
    double result;
    int size_post = postfix.Size();
    for (int i = 0; i < size_post; ++i){
        temp = postfix.Pop();
        if (temp->get_token_type() == "double"){
            primary_stack.Push(static_cast<doubles*>(temp)->get_value());
        }
        else if (temp->get_token_type() == "variable"){
            primary_stack.Push(static_cast<variable*>(temp)->plug_in(vars));
        }
        else if (temp->get_token_type() == "binary"){
            double right = primary_stack.Pop();
            double left = primary_stack.Pop();
            double result_temp = static_cast<binary_fcns*>(temp)->operate(left, right);
            primary_stack.Push(result_temp);
        }
        else if (temp->get_token_type() == "unary"){
            double right = primary_stack.Pop();
            double result_temp = static_cast<unary_fcns*>(temp)->operate(right);
            primary_stack.Push(result_temp);
        }
    }
    result = primary_stack.Pop();
    if (!primary_stack.Empty()){
        cout << "ERROR: POSTFIX INCORRECT: result inaccurate" << endl;
        return 999999999999999999999999;
    }
    return result;
}
