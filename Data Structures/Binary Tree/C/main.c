/** @file main.c
* 
* @brief Binary Tree implementation
*
*@author Lajos Onodi Neto
*/

#include "bintree.h"
#include <stdio.h>

int main(){

    BinTree *binTree = new_bintree();
    put(binTree, 30);
    put(binTree, 20);
    put(binTree, 10);
    put(binTree, 50);
    print_inorder(binTree->root);
    
    printf("\n\n");
    return 0;
}