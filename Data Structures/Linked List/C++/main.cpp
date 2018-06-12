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
    linkedList.PushFront(55);
    linkedList.PushFront(50);
    linkedList.PushBack(55);
    linkedList.PushBack(55);
    linkedList.Print();
    std::cout << "\n";
    std::cout << "First item : " << linkedList.GetFront();
    std::cout << "\n";
    std::cout << "Last item : " << linkedList.GetBack();
    std::cout << "\n";
    std::cout << "Value at given index: " << linkedList.ValueAt(2);
    std::cout << "\n";
    linkedList.PopFront();
    linkedList.Print();
    std::cout << "\n";
    linkedList.PopBack();
    linkedList.Print();
    std::cout << "\n";
    linkedList.InsertAt(0,55);
    linkedList.Print();
    std::cout << "\n";
    linkedList.InsertAt(1,55);
    linkedList.Print();
    std::cout << "\n";
    linkedList.InsertAt(3,77);
    linkedList.Print();
    std::cout << "\n";
    linkedList.InsertAt(4,55);
    linkedList.Print();
    linkedList.RemoveAt(3);
    std::cout << "\n";
    linkedList.Print();
    linkedList.PushBack(33);
    std::cout << "\n";
    linkedList.Print();
    linkedList.RemoveValue(55);
    std::cout << "\n";
    linkedList.Print();

    std::cout << "\n";
    return 0;
}