/** @file linkedlist_cpp.h
* 
* @brief Linked list implementation
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H
#include <memory>

struct LinkedListNode {
    int value;
    LinkedListNode *next;
};

namespace linkedlist {

    class LinkedList {
        public:
        // Constructor
        LinkedList();
        // Returns the size of the linked list
        int GetSize();
        
        private:
        LinkedListNode *head, *tail;
        int total_size;

    };
}

#endif  // PROJECT_LINKEDLIST_H