/** @file queuecpp.h
* 
* @brief Queue implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H
#include <memory>

struct Node{
    int value;
    struct Node *next;
};

namespace queue{

    class Queue{

        public:
        // Constructor
        Queue();
        // Print queue nodes values
        void Print();
        // Check if queue is empty
        int IsEmpty();
        // Enqueue a new node into de queue
        void Enqueue(int value);
        // Dequeue a node from the queue
        void Dequeue();

        private:
        Node *head;
        Node *tail;
    };
}

#endif