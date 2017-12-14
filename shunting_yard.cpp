#include "shunting_yard.h"

shunting_yard::shunting_yard(){
    //empty1111!!!!
}
shunting_yard::shunting_yard(queue<token *> input){
    _infix = queue<token*>(input);
}
bool shunting_yard::check_precedence(token *temp){
    const bool debug = false;
    if (debug){
        cout << "check precedence called**********" << endl;
    }
    if (temp->get_data() == "("){
        _stack.Push(temp);
        if (debug){
            cout << "open parentheses added to stack" << endl;
        }
        return true;
    }
    else if(temp->get_data() == ")"){
        while (_stack.Top()->get_data() != "("){
            _postfix.Push(_stack.Pop());
        }
        _stack.Pop();
        return true;
    }

    if (_stack.Empty()){
        _stack.Push(temp);
        if (debug){
            cout << "some operation added to stack" << endl;
        }
    }
    else if (temp->get_precedence() <= _stack.Top()->get_precedence()){
        _postfix.Push(_stack.Pop());
        if (debug){
            cout << "check precedence: stack popped to postfix, about to call recursively" << endl;
        }
        check_precedence(temp);
    }
    else{
        _stack.Push(temp);
        if (debug){
            cout << "check precedence: operation added to stack, exiting recursive fcn" << endl;
        }
    }
}

void shunting_yard::sh_yrd(){
    const bool debug = false;
    if (debug){
        cout << "shunting yard called" << endl;
    }
    token* temp;
    int size_if = _infix.Size();
    if (debug){
        cout << "shunting yard: all initialized" << endl;
    }
    for (int i = 0; i < size_if; ++i){
        temp = _infix.Pop();
        if (temp->get_token_type() == "double"){
            _postfix.Push(temp);
            if (debug){
                cout << "double added to postfix" << endl;
            }
        }
        else if (temp->get_token_type() == "variable"){
            _postfix.Push(temp);
            if (debug){
                cout << "variable added to postfix" << endl;
            }
        }
        else{
            if (debug){
                cout << "shunting yard: about to check precedence" << endl;
            }
            check_precedence(temp);
            if (debug){
                cout << "shunting yard: got through check precedence" << endl;
            }
        }
        if (i == size_if - 1){//if at end of queue
            if (!_stack.Empty()){
                for (int i = 0; i <= _stack.Size(); ++i){//iterate through stack and pop all
                    _postfix.Push(_stack.Pop());
                }
            }
            else{
                break;
            }
        }
    }
}
