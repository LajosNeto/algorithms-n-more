/** @file stack.h
* 
* @brief Stack implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_STACK_H
#define PROJECT_STACK_H

typedef struct StackNode{
    int value;
    struct StackNode *next;
} StackNode;

typedef struct Stack{
    StackNode *head;
    StackNode *tail;
} Stack;

// Creates a new stack
Stack *new_stack();


#endif