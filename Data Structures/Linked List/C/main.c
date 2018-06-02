/** @file linkedlist.h
* 
* @brief Linked list implementation
*
*@author Lajos Onodi Neto
*/

#include "linkedlist.h"
#include <stdio.h>

int main(){
    LinkedList *linkedList = new_linked_list();
    linkedlist_push_begin(linkedList, 12);
    linkedlist_push_begin(linkedList, 22);
    linkedlist_push_begin(linkedList, 44);
    linkedlist_push_begin(linkedList, 55);
    linkedlist_push_begin(linkedList, 22);
    linkedlist_push_begin(linkedList, 22);
    printf("\n");
    linkedlist_print(linkedList);
    printf("\n");
    linkedlist_delete_value(linkedList, 22);
    printf("\n");
    linkedlist_print(linkedList);
    printf("\n");

    return 0;
}