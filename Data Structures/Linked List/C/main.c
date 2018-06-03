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
    linkedlist_push_begin(linkedList, 10);
    linkedlist_push_begin(linkedList, 20);
    linkedlist_push_begin(linkedList, 30);
    linkedlist_push_begin(linkedList, 40);
    linkedlist_push_begin(linkedList, 50);
    linkedlist_push_begin(linkedList, 60);
    printf("\n");
    linkedlist_print(linkedList);
    printf("\n");
    //linkedlist_delete_value(linkedList, 22);
    linkedlist_reverse(linkedList);
    printf("\n");
    linkedlist_print(linkedList);
    printf("\n");

    return 0;
}