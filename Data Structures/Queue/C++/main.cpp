/** @file main.cpp
* 
* @brief Queue implementation based on linked lists
*
*@author Lajos Onodi Neto
*/

#include "queuecpp.h"
#include <iostream>

int main(int argc, char const *argv[])
{

    queue::Queue queue;
    std::cout << "Is queue empty? - " << queue.IsEmpty();
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    std::cout << "\n";
    queue.Print();
    std::cout << "\n";
    std::cout << "Is queue empty? - " << queue.IsEmpty();

    std::cout << "\n";
    return 0;
}
