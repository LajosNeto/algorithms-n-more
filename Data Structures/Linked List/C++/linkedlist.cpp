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

    LinkedListNode* LinkedList::NewNode(int value){
        LinkedListNode *new_node = new LinkedListNode;
        new_node->value = value;
        new_node->next = NULL;
        return new_node;
    }

    void LinkedList::Print(){
        LinkedListNode *temp = head;
        while(temp!=NULL){ 
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
    }

    int LinkedList::GetSize(){ return total_size; }

    int LinkedList::IsEmpty(){ return (head == NULL) ? 1 : 0; }

    int LinkedList::GetFront(){
        if(IsEmpty()){
            std::cout << "Error - empty linked list\n";
            exit(EXIT_FAILURE);
        }
        return head->value;
    }

    int LinkedList::GetBack(){
        if(IsEmpty()){
            std::cout << "Error - empty linked list\n";
            exit(EXIT_FAILURE);
        }
        return tail->value;
    }

    void LinkedList::PushFront(int value){
        LinkedListNode *new_node = NewNode(value);

        if(IsEmpty()){
            head = new_node;
            tail = new_node;
            ++total_size;
        }
        else{
            new_node->next = head;
            head = new_node;
            ++total_size;
        }
    }

    void LinkedList::PushBack(int value){
        LinkedListNode *new_node = NewNode(value);

        if(IsEmpty()){
            head = new_node;
            tail = new_node;
            ++total_size;
        }
        else{
            tail->next = new_node;
            tail = new_node;
            ++total_size;
        }
    }

    int LinkedList::ValueAt(int index){
        if(index < 0 || index >= total_size){
            std::cout << "Error - index out of range.";
            exit(EXIT_FAILURE);
        }
        LinkedListNode *temp = head;
        for(int i=0; i<index; i++) temp = temp->next;

        return temp->value;
    }
}