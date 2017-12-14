#ifndef LINKED_LIST_STRUCT_H
#define LINKED_LIST_STRUCT_H

#include <iostream>
using namespace std;
template <class ITEM_TYPE>
struct node {
    ITEM_TYPE _item;
    node* _next;
    node();
    node(ITEM_TYPE item);
    template <class T>
    friend ostream& operator <<(ostream& outs, const node<T> &print_me);
};
template <class ITEM_TYPE>
node<ITEM_TYPE>::node(){
    _item = ITEM_TYPE();
    _next = nullptr;
}
template <class ITEM_TYPE>
node<ITEM_TYPE>::node(ITEM_TYPE item) {
    _item = item;
    _next = nullptr;
}
template <class T>
ostream& operator <<(ostream& outs, const node<T> &print_me){
    outs << print_me._item;
    return outs;
}
#endif // LINKED_LIST_STRUCT_H
