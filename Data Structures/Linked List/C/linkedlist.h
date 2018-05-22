/** @file linkedlist.h
* 
* @brief Linked list implementation
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H

#endif  // PROJECT_LINKEDLIST_H

typedef struct ListNode{
    int value;
    struct ListNode *next;
};

typedef struct LinkedList{
    struct ListNode *head;
    struct ListNode *tail;
};

LinkedList *new_linked_list();