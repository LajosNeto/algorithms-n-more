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
    dinarray_push(dinArray,3);
    dinarray_push(dinArray,4);
    printf("Array actual capacity = %d\n",dinArray->totalCapacity);
    dinarray_push(dinArray,5);
    printf("Array actual capacity = %d\n",dinArray->totalCapacity);
    dinarray_print_data(dinArray);
    dinarray_push(dinArray,6);
    dinarray_push(dinArray,7);
    dinarray_push(dinArray,8);
    dinarray_push(dinArray,9);
    printf("Array actual capacity = %d\n",dinArray->totalCapacity);
    dinarray_push(dinArray,10);
    printf("Array actual capacity = %d\n",dinArray->totalCapacity);
    dinarray_print_data(dinArray);
    printf("\n\n");
}