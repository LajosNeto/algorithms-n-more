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
    dinArray.Push(50);
    std::cout << dinArray.GetCapacity();
    std::cout << "\n";
    dinArray.PrintData();
    std::cout << "\n";
    dinArray.Insert(0, 111);
    std::cout << "\n";
    dinArray.PrintData();
    dinArray.Prepend(222);
    std::cout << "\n";
    dinArray.PrintData();
    dinArray.Delete(1);
    std::cout << "\n";
    dinArray.PrintData();
    std::cout << "\n";

    return 0;
}
