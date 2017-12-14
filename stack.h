#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>
using namespace std;

template <class T>
class stack {
private:
    std::vector<T> _stack;
public:
    stack();
    explicit stack(T input[]);
    T Push(T thing);                                           //insert at end (top)
    T Pop();                                            //extract from end (top)
    T Top() const;                                            //peak at end value (top)
    bool Empty();                                       //check if stack is empty
    int Size() const;                                         //return size of stack
    template <class U>
    friend ostream& operator <<(ostream& outs, const stack<U>& rhs);
};

template <class T>
stack<T>::stack() {}
template <class T>
stack<T>::stack(T *input) {
    for (int i = 0; i < sizeof(input); ++i){
        _stack.push_back(input[i]);
    }
}

template <class T>
T stack<T>::Push(T thing) {
    _stack.push_back(thing);
    return thing;
}
template <class T>
T stack<T>::Pop() {
    T pop_val = _stack.back();
    _stack.pop_back();
    return pop_val;
}
template <class T>
T stack<T>::Top() const {
    return _stack.back();
}

template <class T>
bool stack<T>::Empty() {
    if (_stack.size() == 0){
        return true;
    }
    else {
        return false;
    }
}
template <class T>
int stack<T>::Size() const {
    return _stack.size();
}
template <class U>
ostream& operator <<(ostream &outs, const stack<U> &rhs) {
    outs << "<";
    for (int i = 0; i < rhs._stack.size(); ++i){
        outs << "  " << rhs._stack[i];
    }
    outs << "  >";
    return outs;
}

#endif // STACK_H
