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
    
    std::cout << "\n";
    return 0;
}
