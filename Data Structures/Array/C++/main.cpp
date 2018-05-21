#include "dinarray.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    /* code */
    darray::DinArray dinArray;
    /* dinArray.Push(10);
    dinArray.Push(20);
    dinArray.Push(30);
    dinArray.Push(40);
    std::cout << "\n";
    std::cout << dinArray.GetCapacity();
    std::cout << "\n"; */
    dinArray.Push(10);
    dinArray.Push(30);
    dinArray.Push(30);
    dinArray.Push(30);
    dinArray.Push(30);
    dinArray.Push(30);
    dinArray.Push(30);
    dinArray.Push(10);
    std::cout << "\n";
    dinArray.PrintData();
    std::cout << "\n";
    dinArray.Remove(30);
    std::cout << "\n";
    dinArray.PrintData();
    std::cout << "\n";

    return 0;
}
