/** @file array.h
* 
* @brief Dynamic array implementation
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H
#define DIN_ARRAY_INITIAL_CAPACITY 5
#define MIN_CAPACITY 5
#define GROW_FACTOR 2

//#include <assert.h>
//#include <stdbool.h>

typedef struct DinArray{
    int totalSize;
    int totalCapacity;
    int *data;
} DinArray;

// Create new DinArray
DinArray *new_dinarray();
// Resize DinArray to new size (grow or shrink)
void dinarray_check_resize(DinArray *dinArray, int newSize);
// Get actual DinArray size
int dinarray_size(DinArray *dinArray);
// Get actual total capacity
int dinarray_capacity(DinArray *dinArray);
// Check if array is empty
int dinarray_is_empty(DinArray *dinArray);
// Push new value in last position
void dinarray_push(DinArray *dinArray, int value);
// Return value at given index
int dinarray_at(DinArray *dinArray, int index);
// Print all items
void dinarray_print_data(DinArray *dinArray);
// Insert a new value at given position. Shifts items to the right
void dinarray_insert(DinArray *dinArray, int index, int value);
// Insert a new value at the first position
void dinarray_prepend(DinArray *dinArray, int value);
// Remove the last item on the DinArray
void dinarray_pop(DinArray *dinArray);
// Delete item at a given position. Shifts items to the left
void dinarray_delete(DinArray *dinArray, int index);

#endif  // PROJECT_ARRAY_H