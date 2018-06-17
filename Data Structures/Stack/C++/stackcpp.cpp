/** @file stackcpp.cpp
* 
* @brief Stack implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#include <iostream>
#include "stackcpp.h"

namespace stack{

    Stack::Stack(){
        head = NULL;
        tail = NULL;
    }

    int Stack::IsEmpty(){
        return (head == NULL ? 1 : 0);
    }

    void Stack::Print(){
        Node *temp = head;
        while(temp!=NULL){
            std::cout << temp->value << "\n|\n";
            temp = temp->next;
        }
    }

}