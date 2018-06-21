/** @file bintree.c
* 
* @brief Binary Tree implementation
*
*@author Lajos Onodi Neto
*/

#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree *new_bintree(){
    
    BinTree *binTree = malloc(sizeof(BinTree));
    binTree->root = NULL;
    return binTree;
}

Node *new_node(int value){
    
    Node *new_node = malloc(sizeof(Node));
    new_node->key = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *put_aux(Node *root, int value){

    if (root == NULL) return new_node(value);
    else if(value < root->key) root->left = put_aux(root->left, value);
    else if(value > root->key) root-> right = put_aux(root->right,value);
    else root->key = value;

    return root;
}

void put(BinTree *binTree, int value){

    binTree->root = put_aux(binTree->root, value);
}

void print_inorder(Node *node){
    
    if(node == NULL) {
        return;
    }
    print_inorder(node->left);
    printf("%d", node->key);
    print_inorder(node->right);
}
