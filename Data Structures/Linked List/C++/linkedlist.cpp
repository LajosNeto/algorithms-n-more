/* @file linkedlist.cpp
 
@brief Linked List implementation

@author Lajos Onodi Neto
 */

#include <iostream>
#include "linkedlist_cpp.h"

namespace linkedlist {

    LinkedList::LinkedList(){
        head = NULL;
        tail = NULL;
        total_size = 0;
    }

    int LinkedList::GetSize(){ return total_size; }
}