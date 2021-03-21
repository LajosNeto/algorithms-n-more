/** @file queuecpp.cpp
* 
* @brief Queue implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#include "queuecpp.h"
#include <iostream>

namespace queue{

    Queue::Queue(){
        head = NULL;
        tail = NULL;
    }

    void Queue::Print(){
        Node *temp = head;
        while(temp != NULL){
            std::cout << temp->value << " <- ";
            temp = temp->next;
        }
    }

    int Queue::IsEmpty(){
        return (head == NULL ? 1 : 0);
    }

    void Queue::Enqueue(int value){
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = NULL;

        if(IsEmpty()){
            head = new_node;
            tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }

    void Queue::Dequeue(){
        Node *temp_free = head;

        if(IsEmpty()){
            std::cout << "\nError - empty queue.\n";
            exit(EXIT_FAILURE);
        }
        else if(head == tail){
            head = NULL;
            tail = NULL;
        }
        else{
            head = head->next;
        }
        free(temp_free);
    }

}