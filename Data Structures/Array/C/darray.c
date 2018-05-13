/** @file array.c
* 
* @brief Dynamic array implementation
*
*@author Lajos Onodi Neto
*/

#include "darray.h"
#include <stdlib.h>
#include <stdio.h>

DinArray *new_dinarray(){
    DinArray *dinArray = malloc(sizeof(DinArray));
    dinArray->totalCapacity = DIN_ARRAY_INITIAL_CAPACITY;
    dinArray->totalSize = 0;
    dinArray->data = (int*)malloc(sizeof(int)*DIN_ARRAY_INITIAL_CAPACITY);
    return dinArray;
}

void reallocate_data(DinArray *dinArray, int *newData, int new_capacity){
    for(int i=0; i<dinArray->totalSize; i++){
        *(newData+i) = *(dinArray->data+i);
    }
    free(dinArray->data);
    dinArray->data = newData;
    dinArray->totalCapacity = new_capacity;
}

void dinarray_check_resize(DinArray *dinArray, int newSize){
    if(newSize >= dinArray->totalCapacity){
        printf("\nARRAY GROOOOOW\n");
        int new_capacity = dinArray->totalCapacity * GROW_FACTOR;
        int *newDinArrayData = (int*)malloc(sizeof(int)*new_capacity);
        reallocate_data(dinArray, newDinArrayData, new_capacity);
    }
    else if(newSize < dinArray->totalSize){
        if(dinArray->totalSize < dinArray->totalCapacity/GROW_FACTOR){
            printf("ENTROU");
            int current_capacity = dinArray->totalCapacity;
            int new_capacity  = dinArray->totalCapacity/GROW_FACTOR;

            if(new_capacity < MIN_CAPACITY) new_capacity = MIN_CAPACITY;
            
            if(new_capacity != current_capacity){
                int *newDinArrayData = (int*)malloc(sizeof(int)*new_capacity);
                reallocate_data(dinArray, newDinArrayData, new_capacity);
            }
        }
    }
}

int dinarray_size(DinArray *dinArray){
    return dinArray->totalSize;
}

int dinarray_capacity(DinArray *dinArray){
    return dinArray->totalCapacity;
}

int dinarray_is_empty(DinArray *dinArray){
    if(dinArray->totalSize<1) return 1;
    return 0;
}

void dinarray_push(DinArray *dinArray, int value){
    dinarray_check_resize(dinArray, dinArray->totalSize+1);
    *(dinArray->data+(dinArray->totalSize)) = value;
    ++(dinArray->totalSize);
}

void dinarray_print_data(DinArray *dinArray){
    for(int i=0; i<dinArray->totalSize; i++) printf("%d ->",*(dinArray->data+i));
}

int dinarray_at(DinArray *dinArray, int index){
    if(index>=dinArray->totalSize || index<0) return 0;
    return *(dinArray->data+index);
}

void dinarray_insert(DinArray *dinArray, int index, int value){
    if(index>dinArray->totalSize+1||index<=0){
        printf("Invalid operation. Negative index or trying to insert on invalid position");
        return;
    }

    dinarray_check_resize(dinArray, dinArray->totalSize+1);
    for(int j=dinArray->totalSize; j>=index; j--){
        *(dinArray->data+j) = *(dinArray->data+(j-1));
    }
    *(dinArray->data+(index-1)) = value;
    ++(dinArray->totalSize);
}

void dinarray_prepend(DinArray *dinArray, int value){
    dinarray_insert(dinArray, 1, value);
}

void dinarray_pop(DinArray *dinArray){
    if(dinArray->totalSize == 0) exit(EXIT_FAILURE);
    dinarray_check_resize(dinArray, dinArray->totalSize-1);
    dinArray->totalSize--;
}

void dinarray_delete(DinArray *dinArray, int index){
    if(index>dinArray->totalSize||index<=0){
        printf("Invalid operation. Negative index or trying to insert on invalid position");
        return;
    }

    dinarray_check_resize(dinArray, dinArray->totalSize-1);
    
    for(int i=index-1; i<=dinArray->totalSize-2; i++){
        *(dinArray->data+i) = *(dinArray->data+(i+1));
    }
    --(dinArray->totalSize);
}

void dinarray_remove(DinArray *dinArray, int value){
    for (int i=0; i< dinArray->totalSize; i++){
        if(*(dinArray->data+i) == value) dinarray_delete(dinArray, i+1);
    }
}