/** @file linkedlist.h
* 
* @brief Linked list implementation
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H


typedef struct LinkedListNode{
    int value;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList{
    struct LinkedListNode *head;
    struct LinkedListNode *tail;
    int size;
} LinkedList;


// Creates a new linked list
LinkedList *new_linked_list();
// Checks if the linked list is empty
int linkedlist_is_empty(LinkedList *linkedList);
// Return linked list size
int linkedlist_size(LinkedList *linkedList);
// Add a new node at the beginning of the linked list
void linkedlist_push_begin(LinkedList *linkedList, int value);
// Add a new node at the end of the linked list
void linkedlist_push_end(LinkedList *linkedList, int value);
// Remove the first node/value
void linkedlist_pop_begin(LinkedList *linkedList);
// Print linked list values
void linkedlist_print(LinkedList *linkedList);
// Returns front item
int linkedlist_get_front(LinkedList *linkedList);
// Returns back item
int linkedlist_get_back(LinkedList *linkedList);

#endif  // PROJECT_LINKEDLIST_H