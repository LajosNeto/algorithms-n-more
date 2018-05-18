/* @file dinarray.cpp
 
@brief Dynamic array implementation

@author Lajos Onodi Neto
 */

#include <iostream>
#include "dinarray.h"

namespace darray{

    DinArray::DinArray(){
        data = std::unique_ptr<int[]>(new int[initialCapacity]);
        total_capacity = initialCapacity;
        total_size = 0;
    }

    int DinArray::GetSize(){ return total_size; }

    int DinArray::GetCapacity(){ return total_capacity; }

    bool DinArray::IsEmpty(){ return total_size == 0; }

    int DinArray::GetValueAtPosition(int index){
        if(index < 0 || index > total_size){
            std::cout << "Error - Invalid index";
            exit(EXIT_FAILURE);
        }
        return data[index];
    }

    void DinArray::ReallocateData(int new_capacity){
        std::unique_ptr<int[]> new_data(new int[new_capacity]);
        for(int i = 0; i<total_size; i++){ new_data[i] = data[i]; }
        data = std::move(new_data);
        total_capacity = new_capacity;

    }

    void DinArray::CheckResize(int new_size){
        if(new_size >= total_capacity){
            int new_capacity = total_capacity*growFactor;
            ReallocateData(new_capacity);

        }
        else if (new_size < total_size){
            if(new_size < total_capacity/growFactor){
                int new_capacity = total_capacity/growFactor;
                if(new_capacity<minCapacity) new_capacity = minCapacity;
                ReallocateData(new_capacity);
            }
        }
        
    }

    void DinArray::Push(int value){
        CheckResize(total_size+1);
        data[total_size] = value;
        ++total_size;
    }

    void DinArray::Pop(){
        CheckResize(total_size-1);
        --total_size;
    }

}