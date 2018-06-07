/** @file main.cpp
* 
* @brief Linked list implementation
*
*@author Lajos Onodi Neto
*/

#include "linkedlist_cpp.h"
#include <iostream>

int main(int argc, char const *argv[]){

    linkedlist::LinkedList linkedList;
    std::cout << "\n" << linkedList.GetSize() << "\n";
    std::cout << "\n" << linkedList.IsEmpty() << "\n";
    linkedList.PushFront(10);
    linkedList.PushFront(50);
    linkedList.PushBack(40);
    linkedList.PushBack(90);
    linkedList.Print();
    std::cout << "\n";
    std::cout << "First item : " << linkedList.GetFront();

    std::cout << "\n";
    return 0;
}