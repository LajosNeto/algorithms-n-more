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
        // Creates a new node
        LinkedListNode *NewNode(int value);
        // Print the linked list
        void Print();
        // Returns the size of the linked list
        int GetSize();
        // Check if linked list is empty
        int IsEmpty();
        // Push new node in front
        void PushFront(int value);
        // Push new node in back
        void PushBack(int value);
        
        private:
        LinkedListNode *head, *tail;
        int total_size;

    };
}

#endif  // PROJECT_LINKEDLIST_H