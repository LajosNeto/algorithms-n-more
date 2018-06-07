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
    
    return 0;
}