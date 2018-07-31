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
    put(binTree, 55);
    put(binTree, 60);
    put(binTree, 100);
    put(binTree, 70);
    put(binTree, 63);
    print_inorder(binTree->root);
    printf("\n");
    print_preorder(binTree->root);
    printf("\n");
    print_increase_order(binTree->root);
    printf("\n");
    printf("Min value : %d",min_value(binTree->root));
    printf("\n");
    printf("Max value : %d",max_value(binTree->root));
    printf("\n");
    printf("%d", check_value(binTree->root, 30));
    printf("\n");
    Node *node = get_parent(binTree->root, 55);
    printf("%d", node->key);
    printf("\n");
    Node *valueNode = get_node(binTree->root, 20);
    printf("%d", valueNode->key);

    printf("\n\n");
    return 0;
}