/* @file dinarray.cpp
 
@brief Dynamic array implementation

@author Lajos Onodi Neto
 */

#include <iostream>
#include "dinarray.h"

namespace darray{

    DinArray::DinArray(){
        data = std::unique_ptr<int[]>(new int[initialCapacity]);
    }

    int DinArray::GetSize(){
        return total_size;
    }


}