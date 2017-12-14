#ifndef QUEUE_H
#define QUEUE_H

#include "list_class.h"

template <class T>
class queue {
private:
    List<T> _queue;
public:
    queue();
    explicit queue(T input[]);
    queue(const queue<T>& input);

    T Push(T thing);                                                   //insert at end (back)
    T Pop();                                                    //extract from head (front)
    T Front();                                                  //peak at head value (front)
    bool Empty();                                               //check if queue empty
    int Size();                                                 //return size of queue
    template <class U>
    friend ostream& operator <<(ostream& outs, const queue<U>& rhs);
};

template <class T>
queue<T>::queue() {
}
template <class T>
queue<T>::queue(T *input) {
    for (int i = sizeof(input); i >= 0; --i){
        _queue.insertHead(input[i]);
    }
    _queue.Delete(_queue.End());
}

template <class T>
queue<T>::queue(const queue<T>& input) {
    _queue = input._queue;
}

template <class T>
T queue<T>::Push(T thing) {
    if (!_queue.Begin()){
        _queue.insertHead(thing);
    }
    else{
        _queue.insertAfter(thing, _queue.End());
    }
}
template <class T>
T queue<T>::Pop() {
    T thing = _queue.Begin()->_item;
    _queue.Delete(_queue.Begin());
    return thing;
}
template <class T>
T queue<T>::Front() {
    return _queue[0];
}

template <class T>
bool queue<T>::Empty() {
    if (_queue.Begin() == nullptr){
        return true;
    }
    else{
        return false;
    }
}
template <class T>
int queue<T>::Size() {
    const bool debug = false;
    if (debug){
        cout << "queue: Size called" << endl;
    }
    if (!_queue.Begin()){
        if (debug){
            cout << "error size = 0 tripped" << endl;
        }
        return 0;
    }
    node<T>* walker = _queue.Begin();
    int count = 1;
    while (walker->_next != nullptr){
        walker = walker->_next;
        ++count;
    }
    return count;
}
template <class U>
ostream& operator <<(ostream& outs, const queue<U>& rhs){
    outs << rhs._queue;
    return outs;
}


#endif // QUEUE_H
