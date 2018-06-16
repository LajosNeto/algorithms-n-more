/** @file stack.c
* 
* @brief Stack implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *new_stack(){
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    stack->tail = NULL;
    return stack;
}
