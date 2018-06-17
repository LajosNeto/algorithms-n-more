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
}