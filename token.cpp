
#include "token.h"
#include "variable.h"
#include "binary_fcns.h"
#include "doubles.h"
#include "unary_fcns.h"
#include "special.h"

std::string token::what_type() const {
}
int token::precedence() const {
}
token::token() {
    _data = "";
    _type = "";
    _precedence = 0;
}
token::token(std::string data, std::string type) {
    _data = data;
    _type = type;

    if (_type == "double"){
        _precedence = 0; //doesn't matter
    }
    else if(_type == "binary"){
        if (data == "+"){
            _precedence = 1;
        }
        else if(data == "-"){
            _precedence = 1;
        }
        else if(data == "*"){
            _precedence = 2;
        }
        else if(data == "/"){
            _precedence = 2;
        }
        else if(data == "^"){
            _precedence = 3;
        }
    }
    else if(_type == "unary"){
        _precedence = 3;
    }
    else if(_type == "variable"){
        _precedence = 0; //doesn't matter
    }
    //special: aka () dosn't need a precedence
}
queue<token*> token::tokenize(std::string input) {
    const bool debug = false;
    if (debug){
        cout << "tokenize has been called" << endl;
    }
    queue<token*> output;
    std::string const NUMBERS = "0123456789.";
    std::string const BINARY = "+-*/^";
    std::string const UNARY = "sin cos tan sec csc cot log ln";
    std::string const VARIABLES = "xX";
    std::string const SPECIALS = "()";
    while (!input.empty()){
        if (debug){
            cout << "tokenize: while loop has begun" << endl;
        }
        int next_space = input.find_first_of(' ');
        std::string target = input.substr(0, next_space);

        if (debug){
            cout << "tokenize: if statements about to start" << endl;
        }

        if (NUMBERS.find(target.substr(0,1)) < NUMBERS.length()){
            token* ptr = new doubles(target);
            if (debug){
                cout << "ptr is: " << ptr << endl;
            }
            output.Push(ptr);
            input.erase(0, next_space);
            input.erase(0, 1);
        }
        else if(BINARY.find(target) < BINARY.length()){
            token* ptr = new binary_fcns(target);
            if (debug){
                cout << "ptr is: " << ptr << endl;
            }
            output.Push(ptr);
            input.erase(0, next_space);
            input.erase(0, 1);
        }
        else if(UNARY.find(target) < UNARY.length()){
            token* ptr = new unary_fcns(target);
            if (debug){
                cout << "ptr is: " << ptr << endl;
            }
            output.Push(ptr);
            input.erase(0, next_space);
            input.erase(0, 1);
        }
        else if(VARIABLES.find(target) < VARIABLES.length()){
            token* ptr = new variable;
            if (debug){
                cout << "ptr is: " << ptr << endl;
            }
            output.Push(ptr);
            input.erase(0, next_space);
            input.erase(0, 1);
        }
        else if(SPECIALS.find(target) < SPECIALS.length()){
            token* ptr = new special(target);
            if (debug){
                cout << "ptr is: " << ptr << endl;
            }
            output.Push(ptr);
            input.erase(0, next_space);
            input.erase(0,1);
        }
        if (debug){
            cout << "tokenize: end of iteration" << endl;
        }
    }
    if (debug){
        cout << "tokenize: end of loop, about to return queue" << endl;
    }

    return output;
}
