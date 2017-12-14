#include <iostream>
#include "test_fcns.h"
#include "animate.h"
using namespace std;

int main() {
//    test_stack();
//    test_queue();
//    test_tokenizer();
//    test_shunting_yard();
//    test_rpn();
//    test_graph();

    string temp_function;
    cout << "set initial function: " << endl;
    cout << "> "; getline(cin, temp_function);

    animate game(temp_function);
    game.run();

    return 0;
}
