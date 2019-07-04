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

void enqueue(Queue *queue, int value){
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if(is_empty(queue)){
        queue->head = new_node;
        queue->tail = new_node;
    }
    else{
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

void dequeue(Queue *queue){
    Node *temp_free = queue->head;
    
    if(is_empty(queue)){
        printf("\nError - empty queue\n");
        exit(EXIT_FAILURE);
    }

    if(queue->head == queue->tail){
        queue->head = NULL;
        queue->tail = NULL;
    }
    else{
        queue->head = queue->head->next;
    }

    free(temp_free);
}
