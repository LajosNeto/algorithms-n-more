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

void stack_print(Stack *stack){
    StackNode *temp = stack->head;
    while(temp != NULL){
        printf("\n%d",temp->value);
        temp = temp->next;
    }
}

int stack_is_empty(Stack *stack){
    return (stack->head == NULL ? 1 : 0);
}

int stack_top(Stack *stack){
    return stack->head->value;
}

void stack_push(Stack *stack, int value){
    StackNode *new_node = malloc(sizeof(StackNode));
    new_node->value = value;
    new_node->next = NULL;

    if(stack->head == NULL){
        stack->head = new_node;
        stack->tail = new_node;
    }
    else{
        new_node->next = stack->head;
        stack->head = new_node;
    }
}

