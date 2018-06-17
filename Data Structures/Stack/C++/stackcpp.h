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

        private:
        Node *head;
        Node *tail;

    };

}

#endif