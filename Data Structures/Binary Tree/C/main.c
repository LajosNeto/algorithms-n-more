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
    put(binTree, 25);
    print_inorder(binTree->root);
    printf("\n");
    print_preorder(binTree->root);
    printf("\n");
    print_increase_order(binTree->root);
    printf("\n");
    printf("Min value : %d",min_value(binTree->root));
    
    printf("\n\n");
    return 0;
}