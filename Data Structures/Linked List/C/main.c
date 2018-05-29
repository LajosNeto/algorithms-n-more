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
    if(linkedlist_is_empty(linkedList)) printf("NULL");
    printf("\n");
    linkedlist_push_end(linkedList, 10);
    linkedlist_print(linkedList);
    printf("\n");
    linkedlist_push_end(linkedList, 20);
    linkedlist_print(linkedList);
    printf("\n");
    printf("%d", linkedlist_size(linkedList));
    return 0;
}