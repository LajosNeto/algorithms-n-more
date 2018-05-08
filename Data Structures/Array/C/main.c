/** @file main.c
* 
* @brief Dynamic array implementation - tests
*
*@author Lajos Onodi Neto
*/

#include <stdio.h>
#include "darray.h"

int main(){
    DinArray* dinArray = new_dinarray();
    int size = dinarray_size(dinArray);
    dinarray_push(dinArray,1);
    dinarray_push(dinArray,2);
    dinarray_push(dinArray,14);
    dinarray_push(dinArray,20);
    printf("Array actual capacity = %d",dinArray->totalCapacity);
    dinarray_push(dinArray,32);
    printf("Array actual capacity = %d",dinArray->totalCapacity);
    printf("\n");
    dinarray_print_data(dinArray);
    printf("\n");
    dinarray_push(dinArray,3);
    dinarray_print_data(dinArray);
    printf("\n");
    dinarray_prepend(dinArray, 50);
    printf("\n");
    dinarray_print_data(dinArray);
    printf("\n");
}