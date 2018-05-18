/* @file dinarray.h
 
@brief Dynamic array implementation

@author Lajos Onodi Neto
 */

#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H
#include <memory>

namespace darray {

static const int dinArrayCapacity = 5;
static const int initialCapacity = 5;
static const int minCapacity = 5;
static const int growFactor = 2;

class DinArray {
    public:
    // Constructor, return new DinArray
    DinArray();
    // Return DinArray current total size
    int GetSize();
    // Return DinArray total capacity
    int GetCapacity();
    // Check if DinArray is empty
    bool IsEmpty();
    // Return value stored at a given position
    int GetValueAtPosition(int index);
    // Insert new value in the last position
    void Push(int value);
    // Remove value from the last position
    void Pop();
    
    private:
    int total_capacity ;
    int total_size;
    std::unique_ptr<int[]> data;
    void CheckResize(int new_size);
    void ReallocateData(int new_size);
    

};

}

#endif  // PROJECT_ARRAY_H