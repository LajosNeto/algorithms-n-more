/** @file queue.c
* 
* @brief Queue implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *new_queue(){
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int is_empty(Queue *queue){
    return (queue->head == NULL ? 1 : 0);
}

void print(Queue *queue){
    Node *temp = queue->head;
    while(temp != NULL){
        printf("%d <- ", temp->value);
        temp = temp->next;
    }
}
