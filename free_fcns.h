#ifndef FREE_FCNS_H
#define FREE_FCNS_H

#include "linked_list_struct.h"

//Linked List General Functions:

//insert at the head of list
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertHead(node<ITEM_TYPE> *&head, ITEM_TYPE insertThis);

template <class ITEM_TYPE>
void PrintList(node<ITEM_TYPE>* head);

template <class ITEM_TYPE>
void PrintList_backwards(node<ITEM_TYPE> *head);            //recursive fun! :)

//return ptr to target or NULL
template <class ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE target);

//insert after ptr
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *afterThis, ITEM_TYPE insertThis);

//insert before ptr
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* beforeThis, ITEM_TYPE insertThis);

//ptr to previous node
template <class ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prevToThis);

//delete, return item
template <class ITEM_TYPE>
ITEM_TYPE DeleteNode(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* deleteThis);

template <class ITEM_TYPE>
node<ITEM_TYPE>* CopyList(node<ITEM_TYPE>* head);           //duplicate the list...

template <class ITEM_TYPE>
ITEM_TYPE ClearList(node<ITEM_TYPE>*& head);                     //delete all the nodes

template <class ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos);              //_item at this position

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//insert
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending);

//insert or add if a dup
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending);

//node after which this
//    item goes
//order: 0 ascending
template <class ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* walker, ITEM_TYPE item, bool ascending);
template <class ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head);            //Last Node in the list



template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertHead(node<ITEM_TYPE>* &head, ITEM_TYPE insertThis){
    //insert item at beginning of list
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);
    temp->_next = head;
    head = temp;
    return head;
}
template <class ITEM_TYPE>
void PrintList(node<ITEM_TYPE>* head){
    //print contents of list
    cout << "H->";
    while (head != nullptr){
        cout << " [" << head->_item << "] ";
        head = head->_next;
    }
    cout << "|||" << endl;
}
template <class ITEM_TYPE>
void PrintList_backwards(node<ITEM_TYPE> *head){
    //print contents of list in reverse order
    node<int>* last = LastNode(head);
    node<int>* walker = head;
    cout << "|||->";
    while (walker != nullptr){
        cout << " [" << last->_item << "] ";
        walker = walker->_next;
        last = PreviousNode(head, last);
    }
    cout << "<-H" << endl;
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE target){
    //search through list and return node pointer
    while (head != nullptr){
        if (head->_item == target){
            return head;
        }
        else{
            head = head->_next;
        }
    }
    return nullptr;
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertAfter(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *afterThis, ITEM_TYPE insertThis){
    //insert item after given node pointer
    if (!head){
        return head;
    }
    else if (!afterThis){
        return head;
    }
    node<ITEM_TYPE>* insert_ptr = new node<ITEM_TYPE>(insertThis);
    insert_ptr->_next = afterThis->_next;
    afterThis->_next = insert_ptr;
    return insert_ptr;
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertBefore(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* beforeThis, ITEM_TYPE insertThis){
    //insert item before given node pointer
    if (!head){
        return head;
    }
    else if (!beforeThis){
        return head;
    }
    node<ITEM_TYPE>* insert_ptr = new node<ITEM_TYPE>(insertThis);
    insert_ptr->_next = beforeThis;
    PreviousNode(head, beforeThis)->_next = insert_ptr;
    return insert_ptr;
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prevToThis){
    //return node before given node
    if (head == prevToThis){
        return nullptr;
    }
    else{
        while (head->_next != prevToThis){ //segmentation error here
            head = head->_next;
        }
        return head;
    }
}
template <class ITEM_TYPE>
ITEM_TYPE DeleteNode(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* deleteThis){
    //deletes given node and sews list back together
    if (head == deleteThis){
        head = head->_next;
        ITEM_TYPE contents = deleteThis->_item;
        delete deleteThis;
        return contents;
    }
    else if (!head){
        return deleteThis->_item;
    }
    else{
        node<ITEM_TYPE>* before_thing = PreviousNode(head, deleteThis);
        before_thing->_next = deleteThis->_next;
        ITEM_TYPE contents = deleteThis->_item;
        delete deleteThis;
        return contents;
    }
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* CopyList(node<ITEM_TYPE>* head){
    //copy contents of on list to a new one
    node<ITEM_TYPE>* copy_to = nullptr;
    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* last = LastNode(head);
    while (walker != nullptr){
        InsertHead(copy_to, last->_item);
        walker = walker->_next;
        last = PreviousNode(head, last);
    }
    return copy_to;
}
template <class ITEM_TYPE>
ITEM_TYPE ClearList(node<ITEM_TYPE>*& head){
    //turn list into empty list
    while (head != nullptr){
        return DeleteNode(head, head);
    }
}
template <class ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos){
    //returns value of list element at given position
    for (int i = 0; i <= pos; i++){
        if (pos == 0){
            return head->_item;
        }
        head = head->_next;
    }
    return head->_item;
}


template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending){
    //insert item at appropriate location in sorted list
    node<ITEM_TYPE>* insert_target = WhereThisGoes(head, item, ascending);
    if (insert_target == nullptr){
        return InsertHead(head, item);
    }
    else{
        return InsertAfter(head, insert_target, item);
    }
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending){
    //insert/add item as appropriate into sorted list
    node<ITEM_TYPE>* target_dup = SearchList(head, item);
    if (target_dup != NULL){
        target_dup->_item += item;
        return target_dup;
    }
    else{
        return InsertSorted(head, item, ascending);
    }
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending){
    //returns node pointer to appropriate location for item
    //the node after which to insert
    //will need (head, item, ascending, crazy) as arguments in sorted class version
    node<ITEM_TYPE>* walker = head;
    node<ITEM_TYPE>* shadow = head;
    if (walker){
        walker = walker->_next;
    }

    if (!shadow){
        return nullptr;
    }
    switch (ascending){
        case true:{
            if (item < shadow->_item){
                return nullptr;
            }
            while (shadow){
                if ((item > shadow->_item) && (!shadow->_next)){
                    return shadow;
                }
                else if (item > walker->_item){
                    walker = walker->_next;
                    shadow = shadow->_next;
                }
                else{
                    return shadow;
                }
            }
        }
        case false:{
            if (item > shadow->_item){
                return nullptr;
            }
            while (shadow){
                if ((item < shadow->_item) && (!shadow->_next)){
                    return shadow;
                }
                else if (item < walker->_item){
                    walker = walker->_next;
                    shadow = shadow->_next;
                }
                else{
                    return shadow;
                }
            }
        }
    }
}
template <class ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head){
    //returns node pointer to last element of list
    if (!head){
        return nullptr;
    }
    else{
        while (head->_next != nullptr){
            head = head->_next;
        }
        return head;
    }
}

#endif // FREE_FCNS_H
