#ifndef LIST_CLASS_H
#define LIST_CLASS_H

#include <iostream>
#include "linked_list_struct.h"
#include "free_fcns.h"
#include <cassert>

template <class ITEM_TYPE>
class List {
private:
    node<ITEM_TYPE>* _head;
public:
    List();
    List(node<ITEM_TYPE>* input);

    ~List();
    List(const List<ITEM_TYPE> &copyThis);
    List& operator =(const List& RHS);

    //inset i at the head of list
    node<ITEM_TYPE>* insertHead(ITEM_TYPE i);

    //insert i after iMarker
    node<ITEM_TYPE>* insertAfter(ITEM_TYPE i, node<ITEM_TYPE>* iMarker);

    //insert i before iMarker
    node<ITEM_TYPE>* insertBefore(ITEM_TYPE i, node<ITEM_TYPE>* iMarker);

    //insert i. Assume sorted list
    node<ITEM_TYPE>* insertSorted(ITEM_TYPE i);


    //delete node pointed to by iMarker
    ITEM_TYPE Delete(node<ITEM_TYPE>* iMarker);

    //return pointer to node containing
    node<ITEM_TYPE>* Search(const ITEM_TYPE &key);
    //  key. NULL if not there

    //get the previous node to iMarker
    node<ITEM_TYPE>* Prev(node<ITEM_TYPE>* iMarker);


    //return the item at index
    ITEM_TYPE& operator[](int index);

    //return the head of the list
    node<ITEM_TYPE>* Begin() const;

    //return the tail of the list
    node<ITEM_TYPE>* End() const;

    //insertion operator for list
    template <class U>
    friend ostream& operator <<(ostream& outs, const List<U>& rhs);
};

template <class ITEM_TYPE>
List<ITEM_TYPE>::List() {
    //default ctor
    _head = NULL;
}
template <class ITEM_TYPE>
List<ITEM_TYPE>::List(node<ITEM_TYPE> *input){
    //ctor takes linked list input
    _head = CopyList(input);
}
template <class ITEM_TYPE>
List<ITEM_TYPE>::~List() {
    //destructor of worlds!!
    ClearList(_head);
}
template <class ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE> &copyThis) {
    //copy ctor
    _head = CopyList(copyThis._head);
}
template <class ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>::operator=(const List &RHS) {
    //assignment operator overload
    if (this->_head != RHS._head){
        ClearList(_head);
        _head = CopyList(RHS._head);
    }
    return *this;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insertHead(ITEM_TYPE i) {
    //inserts i at beginning of list
    return InsertHead(_head, i);
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insertAfter(ITEM_TYPE i, node<ITEM_TYPE> *iMarker) {
    //inserts i after given node pointer
    return InsertAfter(_head, iMarker, i);
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insertBefore(ITEM_TYPE i, node<ITEM_TYPE> *iMarker) {
    //inserts i before given node pointer
    return InsertBefore(_head, iMarker, i);
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insertSorted(ITEM_TYPE i) {
    //inserts/adds where appropriate
    InsertSorted_and_add(_head, i, false);
}

template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::Delete(node<ITEM_TYPE> *iMarker) {
    //deletes a single node in list
    return DeleteNode(_head, iMarker);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::Search(const ITEM_TYPE &key) {
    //searches for key and returns node pointer
    return SearchList(_head, key);
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::Prev(node<ITEM_TYPE> *iMarker) {
    //returns previous node pointer to given node pointer
    return PreviousNode(_head, iMarker);
}

template <class ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::operator[](int index) {
    //overloads brackets operator so can snag item of any node in list
    return At(_head, index);
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::Begin() const {
    //returns head of linked list
    return _head;
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::End() const {
    return LastNode(_head);
}


template <class U>
ostream& operator <<(ostream& outs, const List<U>& rhs){
    //overloads output operator
    node<U>* walker = rhs._head;
    while (walker != nullptr){
        outs << *walker << " ";
        walker = walker->_next;
    }
    return outs;
}

#endif // LIST_CLASS_H
