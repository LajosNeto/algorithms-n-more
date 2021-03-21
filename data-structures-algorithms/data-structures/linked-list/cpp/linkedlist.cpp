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

    void LinkedList::PopFront(){
        if(IsEmpty()){
            std::cout << "Error - empty linked list.\n";
            exit(EXIT_FAILURE);
        }

        LinkedListNode *temp_free = head;
        head = head->next;
        free(temp_free);
        --total_size;
    }

    void LinkedList::PopBack(){
        if(IsEmpty()){
            std::cout << "Error - empty linked list.\n";
            exit(EXIT_FAILURE);
        }

        if(head == tail){
            LinkedListNode *temp = head;
            head = NULL;
            tail = NULL;
            free(temp);
            --total_size;
        }
        else{
            LinkedListNode *temp = head;
            LinkedListNode *temp_prev = head;
            while(temp->next != NULL){
                temp_prev = temp;
                temp = temp->next;
            }
            tail = temp_prev;
            temp_prev->next = NULL;
            free(temp);
            --total_size;
        }
    }

    void LinkedList::InsertAt(int index, int value){
        if(index < 0 || index >= total_size){
            std::cout << "Error - index out of range.\n";
            exit(EXIT_FAILURE);
        }

        if(index == 0){
            PushFront(value);
        }
        else{
            LinkedListNode *new_node = NewNode(value);
            LinkedListNode *temp = head;
            for(int i=0; i<index-1; i++) temp = temp->next;
            new_node->next = temp->next;
            temp->next = new_node;
            ++total_size;
        } 
    }

    void LinkedList::RemoveAt(int index){
        if(IsEmpty()){
            std::cout << "Error - empty linked list.\n";
            exit(EXIT_FAILURE);
        }

        else if(index < 0 || index >= total_size){
            std::cout << "Error - index out of range.\n";
            exit(EXIT_FAILURE);
        }

        else if(index == 0) PopFront();

        else if(index == total_size-1) PopBack();

        else{
            LinkedListNode *temp = head;
            LinkedListNode *temp_prev = head;
            for(int i=0; i<index; i++){
                temp_prev = temp;
                temp = temp->next;
            }
            temp_prev->next = temp->next;
            free(temp);
            --total_size;
        }
    }

    void LinkedList::RemoveValue(int value){
        if(IsEmpty()){
            std::cout << "Error - empty linked list.\n";
            exit(EXIT_FAILURE);
        }

        LinkedListNode *temp_prev = head;
        LinkedListNode *temp = head;

        while(temp!=NULL){
            if(temp->value == value){
                if(temp == head){
                    PopFront();
                    temp = head;
                }

                else if(temp == tail) PopBack();

                else{
                    LinkedListNode *temp_free = temp;
                    temp_prev->next = temp->next;
                    temp = temp->next;
                    free(temp_free);
                    --total_size;
                }
            }
            else{
                temp_prev = temp;
                temp = temp->next;
            }
        }
    }

    void LinkedList::Reverse(){
        if(IsEmpty()){
            std::cout << "Error - empty linked list.\n";
            exit(EXIT_FAILURE);
        }

        if(total_size != 1){
            LinkedListNode *temp_prev = head;
            LinkedListNode *temp = temp_prev->next;
            
            while(temp){
                temp_prev->next = temp->next;
                temp->next = head;
                head = temp;
                temp = temp_prev->next;
            }
        }
    }

    int LinkedList::NthFromEnd(int index){
       if(IsEmpty()){
            std::cout << "Error - empty linked list.\n";
            exit(EXIT_FAILURE);
        }

        int index_from_start = (total_size-index)-1;
        LinkedListNode *temp = head;
        for (int i=0; i<=index_from_start; i++) temp = temp->next;
        return temp->value;
    }

    int LinkedList::ValueAt(int index){
        if(index < 0 || index >= total_size){
            std::cout << "Error - index out of range.\n";
            exit(EXIT_FAILURE);
        }

        if(index < 0 || index > total_size){
            std::cout << "Error - index out of range.\n";
            exit(EXIT_FAILURE);
        }

        LinkedListNode *temp = head;
        for(int i=0; i<index; i++) temp = temp->next;

        return temp->value;
    }
}