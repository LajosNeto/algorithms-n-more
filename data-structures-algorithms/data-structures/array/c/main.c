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
    printf("\n");
    dinarray_push(dinArray,666);
    printf("\n");
    dinarray_push(dinArray,100);
    printf("\n");
    dinarray_push(dinArray,666);
    printf("\n");
    dinarray_push(dinArray,100);
    printf("\n");
    dinarray_print_data(dinArray);
    printf("\n");
    dinarray_remove(dinArray, 666);
    printf("\n");
    dinarray_print_data(dinArray);
    printf("\n");
    int find = dinarray_find(dinArray, 20);
    printf("%d", find);
    printf("\n");

    //dinarray_remove(dinArray, 666);
    //printf("\n");
    //dinarray_print_data(dinArray);
    //printf("\n");

    /* for(int i=1; i<=6; i++){
        dinarray_pop(dinArray);
        printf("\n");
        printf("Array actual capacity = %d",dinArray->totalCapacity);
        printf("\n");
        dinarray_print_data(dinArray);
        printf("\n"); */
    //}
}