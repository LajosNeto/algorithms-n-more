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
            std::cout << "\n|\n" << temp->value;
            temp = temp->next;
        }
    }

    void Stack::Push(int value){
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = NULL;

        if(IsEmpty()){
            head = new_node;
            tail = new_node;
        }
        else{
            new_node->next = head;
            head = new_node;
        }
    }

    void Stack::Pop(){
        if(IsEmpty()){
            std::cout << "Error - empty stack\n";
            exit(EXIT_FAILURE);
        }

        Node *temp_free = head;
        head = head->next;
        free(temp_free);
    }

    int Stack::Top(){
        return head->value;
    }

}