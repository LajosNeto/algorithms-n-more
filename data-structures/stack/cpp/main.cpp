/** @file main.cpp
* 
* @brief Stack implementation based on linked lists
*
*@author Lajos Onodi Neto
*/


#include "stackcpp.h"
#include <iostream>

int main(int argc, char const *argv[]){

    stack::Stack stack;
    std::cout << stack.IsEmpty() << "\n";
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Print();
    std::cout << "\n";
    stack.Pop();
    stack.Print();
    std::cout << "\n";
    stack.Pop();
    stack.Print();
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Current TOP item is: " << stack.Top();
    std::cout << "\n";
    
    std::cout << "\n";
    return 0;
}