/** @file stackcpp.h
* 
* @brief Stack implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_STACK_H
#define PROJECT_STACK_H
#include <memory>

struct Node{
    int value;
    struct Node *next;
};

namespace stack{

    class Stack{

        public:
        // Constructor
        Stack();
        // Check if stack is empty
        int IsEmpty();
        // Print stack nodes values
        void Print();
        // Push a new node into the stack
        void Push(int value);

        private:
        Node *head;
        Node *tail;

    };

}

#endif