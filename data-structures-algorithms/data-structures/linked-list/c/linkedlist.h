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
// Insert a new node at a given index
void linkedlist_insert_at(LinkedList *linkedList, int index, int value);
// Remove the first node/value
void linkedlist_pop_begin(LinkedList *linkedList);
// Remove the last node/value
void linkedlist_pop_end(LinkedList *linkedList);
// Remove node from a given index
void linkedlist_delete_at(LinkedList *linkedList, int index);
// Remove a given value (all occurrences)
void linkedlist_delete_value(LinkedList *linkedList, int value);
// Returns value store at a given index
int linkedlist_value_at(LinkedList *linkedList, int index);
// Print linked list values
void linkedlist_print(LinkedList *linkedList);
// Returns front item
int linkedlist_get_front(LinkedList *linkedList);
// Returns back item
int linkedlist_get_back(LinkedList *linkedList);
// Reverse the linked list order
void linkedlist_reverse(LinkedList *linkedList);
// Returns n-th element from end
int linkedlist_nth_from_end(LinkedList *linkedList, int index);

#endif  // PROJECT_LINKEDLIST_H