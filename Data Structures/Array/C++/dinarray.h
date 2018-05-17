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


    private:
    int total_capacity {minCapacity};
    int total_size {0};
    std::unique_ptr<int[]> data;


};

}

#endif  // PROJECT_ARRAY_H