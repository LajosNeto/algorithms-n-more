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

void linkedlist_push_end(LinkedList *linkedList, int value){
    LinkedListNode *new_node = malloc(sizeof(LinkedListNode));
    new_node->next = NULL;
    new_node->value = value;

    // Checks if linked list is empty
    if(linkedList->head == NULL && linkedList->tail == NULL){
        linkedList->head = new_node;
        linkedList->tail = new_node;
    }

    else{
        linkedList->tail->next = new_node;
        linkedList->tail = new_node;
    }

    ++linkedList->size;
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