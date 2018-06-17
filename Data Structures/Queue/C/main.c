/** @file main.c
* 
* @brief Queue implementation based on linked lists
*
*@author Lajos Onodi Neto
*/


#include "queue.h"
#include <stdio.h>

int main(){

    Queue *queue = new_queue();
    printf("Is queue empty? - %d", is_empty(queue));
    printf("\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    print(queue);
    dequeue(queue);
    dequeue(queue);
    printf("\n");
    print(queue);

    printf("\n");
    return 0;
}