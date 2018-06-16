/** @file stack.c
* 
* @brief Stack implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#include "stack.h"
#include <stdio.h>

int main(){

    Stack *stack = new_stack();
    stack_push(stack, 10);
    stack_push(stack, 20);
    stack_push(stack, 30);
    stack_print(stack);
    printf("\n");
    printf("\n");

    return 0;
}