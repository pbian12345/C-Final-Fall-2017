#include "test_fcns.h"
#include <iostream>

void print_queue(queue<token *> a){
    token* temp;
    int size_a = a.Size();
    cout << "contents of resulting queue: " << endl;
    for (int i = 0; i < size_a; ++i){
        temp = a.Pop();
        if (temp->get_token_type() == "double"){
            cout << "successful pop" << endl;
            cout << (static_cast<doubles*>(temp))->get_value() << endl;
        }
        else if (temp->get_token_type() == "binary"){
            cout << "successful pop" << endl;
            cout << (static_cast<binary_fcns*>(temp))->get_value() << endl;
        }
        else if (temp->get_token_type() == "unary"){
            cout << "successful pop" << endl;
            cout << (static_cast<unary_fcns*>(temp))->get_value() << endl;
        }
        else if (temp->get_token_type() == "variable"){
            cout << "successful pop" << endl;
            cout << "x" << endl;
        }
        else if (temp->get_token_type() == "special"){
            cout << "successful pop" << endl;
            cout << (static_cast<special*>(temp))->get_value() << endl;
        }
    }
    cout << endl << endl;
}
void test_stack(){
    double array[] = {1.3, 52, 3, 4.0};
    double extra = 3.14159;
    stack<double> a(array);
    cout << "Should be: 1.3, 52, 3, 4.0" << endl;
    cout << "a: " << a << endl << endl;

    a.Push(extra);
    cout << "Should be: 1.3, 52, 3, 4.0, 3.14159" << endl;
    cout << "a: " << a << endl << endl;

    double popped = a.Pop();
    cout << "popped: " << popped << endl;
    cout << "Should be: 1.3, 52, 3, 4.0" << endl;
    cout << "a: " << a << endl << endl;

    double peaked = a.Top();
    cout << "Should be: 4.0" << endl;
    cout << "top: " << peaked << endl << endl;

    int size = a.Size();
    cout << "Should be: 4" << endl;
    cout << "size: " << size << endl << endl;

    bool empty_check = a.Empty();
    cout << "Should be false" << endl;
    cout << empty_check << endl;
    a.Pop();
    a.Pop();
    a.Pop();
    a.Pop();
    empty_check = a.Empty();
    cout << "Should be true" << endl;
    cout << empty_check << endl << endl;
}
void test_queue(){
    double array[] = {1.3, 52, 3, 4.0};
    double extra = 3.14159;
    queue<double> a(array);
    cout << "Should be: 1.3, 52, 3, 4.0" << endl;
    cout << "a: " << a << endl << endl;

    queue<double> b(a);
    cout << "Should be: 1.3, 52, 3, 4.0" << endl;
    cout << "b: " << b << endl << endl;

    b.Push(extra);
    cout << "Should be 1.3, 52, 3, 4.0, 3.14159" << endl;
    cout << "b: " << b << endl << endl;

    b.Push(2.25);
    cout << "Should be 1.3, 52, 3, 4.0, 3.14159, 2.25" << endl;
    cout << "b: " << b << endl << endl;

    double popped = b.Pop();
    cout << "popped: " << popped << endl;
    cout << "Should be 52, 3, 4.0, 3.14159" << endl;
    cout << "b: " << b << endl << endl;

    double peaked = b.Front();
    cout << "top: " << peaked << endl;
    cout << "Should be: 52, 3, 4.0, 3.14159" << endl;
    cout << "b: " << b << endl << endl;

    int size = b.Size();
    cout << "Should be: 5" << endl;
    cout << "size: " << size << endl << endl;

    bool empty_check = b.Empty();
    cout << "Should be false" << endl;
    cout << empty_check << endl;
    for (int i = 1; i <= size; ++i){
        b.Pop();
    }
    empty_check = b.Empty();
    cout << "Should be true" << endl;
    cout << empty_check << endl << endl;

    cout << "Let's populate an empty queue" << endl;
    queue<double> c;
    for (int i = 0; i < 5; ++i){
        c.Push(i + 1);
    }
    cout << "queue has been populated" << endl;
    cout << "contents: " << endl;
    for (int i = 0; i < 5; ++i){
        double temp = c.Pop();
        cout << temp << endl;
    }
}
void test_tokenizer(){
    std::string test_input1 = "4 + 10 * 3 - 2 / 1";
    std::string test_input2 = "4 / 10 * 3 - cos ( 0.5 )";
    cout << "test strings set." << endl;
    queue<token*> a(token::tokenize(test_input1));
    queue<token*> b(token::tokenize(test_input2));
    print_queue(a);
    print_queue(b);
}
void test_shunting_yard(){
    std::string test_input1 = "4 + 10 * 3 - 2 / 1";
    std::string test_input2 = "4 / 10 * 3 - cos ( 0.5 )";
    std::string test_input3 = "( 5 + 3 * 2 ) / 2 - 4";
    cout << "test strings set." << endl;
    queue<token*> a(token::tokenize(test_input1));
    queue<token*> b(token::tokenize(test_input2));
    queue<token*> c(token::tokenize(test_input3));

    shunting_yard test1(a);
    shunting_yard test2(b);
    shunting_yard test3(c);
    cout << "==========================" << endl;
    test1.sh_yrd();
    cout << "==========================" << endl;
    test2.sh_yrd();
    cout << "==========================" << endl;
    test3.sh_yrd();
    cout << "==========================" << endl;
    cout << "test 1 postfix: " << endl;
    print_queue(test1.get_postfix());
    cout << "test 2 postfix: " << endl;
    print_queue(test2.get_postfix());
    cout << "test 3 postfix: " << endl;
    print_queue(test3.get_postfix());
}
void test_rpn(){
    std::string test_input1 = "5 5 + 2 /";
    std::string test_input2 = "2 2 * 2 / 1 1 10 * + +";
    queue<token*> a(token::tokenize(test_input1));
    queue<token*> b(token::tokenize(test_input2));
    cout << "should be 5" << endl;
    cout << rpn::calculate(a)<< endl;
    cout << "should be 13" << endl;
    cout << rpn::calculate(b) << endl;
}
void test_graph(){
    string test1 = "tan ( x )";
    string test2 = "1 + 2 * 3 / 4 - ( x ^ 2 ) / x";
    //swap out tests in below game object
    animate game1(test1);
    game1.run();
}
