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
    return 0;
}