/** @file linkedlist.c
* 
* @brief Linkd list implementation
*
*@author Lajos Onodi Neto
*/

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList *new_linked_list(){
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->size = 0;
    return linkedList;
}

int linkedlist_is_empty(LinkedList *linkedList){
    if(linkedList->head == NULL) return 1;
    return 0;
}

int linkedlist_size(LinkedList *linkedList){
    return linkedList->size;
}

void linkedlist_push_begin(LinkedList *linkedList, int value){
    LinkedListNode *new_node = malloc(sizeof(LinkedListNode));
    new_node->next = NULL;
    new_node->value = value; 

    if(linkedlist_is_empty(linkedList)){
        linkedList->head = new_node;
        linkedList->tail = new_node;
    }
    else{
        new_node->next = linkedList->head;
        linkedList->head = new_node;
    }

    ++linkedList->size;
}

void linkedlist_push_end(LinkedList *linkedList, int value){
    LinkedListNode *new_node = malloc(sizeof(LinkedListNode));
    new_node->next = NULL;
    new_node->value = value;

    if(linkedlist_is_empty(linkedList)){
        linkedList->head = new_node;
        linkedList->tail = new_node;
    }
    else{
        linkedList->tail->next = new_node;
        linkedList->tail = new_node;
    }

    ++linkedList->size;
}

void linkedlist_insert_at(LinkedList *linkedList, int index, int value){
    LinkedListNode *new_node = malloc(sizeof(LinkedListNode));
    new_node->next = NULL;
    new_node->value = value;

    if(index < 0 || index >= linkedList->size){
        printf("Error - index out of bounds");
        exit(EXIT_FAILURE);
    }

    if(linkedlist_is_empty(linkedList)){
        linkedList->head = new_node;
        linkedList->tail = new_node;
        ++linkedList->size;
    }
    else if(index == 0){
        linkedlist_push_begin(linkedList, value);
    }
    else{
        LinkedListNode *prev_index = linkedList->head;
        LinkedListNode *actual_index = linkedList->head;
        for(int i=0; i<index; i++){
            prev_index = actual_index;
            actual_index = actual_index->next;
        }
        new_node->next = actual_index;
        prev_index->next = new_node;
        ++linkedList->size;
    }

}

void linkedlist_pop_begin(LinkedList *linkedList){
    if(linkedlist_is_empty(linkedList)){
        printf("Error - Empty linked list\n");
        exit(EXIT_FAILURE);
    }
    LinkedListNode *temp = linkedList->head;
    linkedList->head = linkedList->head->next;
    if(linkedList->tail == temp) linkedList->tail = linkedList->head;

    free(temp);
    --linkedList->size;
}

void linkedlist_pop_end(LinkedList *linkedList){
    if(linkedlist_is_empty(linkedList)){
        printf("Error - Empty linked list\n");
        exit(EXIT_FAILURE);
    }

    if(linkedList->tail == linkedList->head){
        free(linkedList->tail);
        linkedList->head = NULL;
        linkedList->tail = NULL;
    }
    else{
        LinkedListNode *temp = linkedList->head;
        LinkedListNode *temp_next = linkedList->head;
        while(temp_next != linkedList->tail){
            temp = temp_next;
            temp_next = temp_next->next;
        }

        linkedList->tail = temp;
        temp->next = NULL;
        free(temp_next);
    }

    --linkedList->size;
}

void linkedlist_print(LinkedList *linkedList){
    LinkedListNode *temp = linkedList->head;
    while(temp != NULL){
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
}

int linkedlist_get_front(LinkedList *linkedList){
    return linkedList->head->value;
}

int linkedlist_get_back(LinkedList *linkedList){
    return linkedList->tail->value;
}