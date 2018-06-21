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

Node *put_aux(Node *node, int value){
    
    if(node == NULL) return new_node(value);

    else if(value < node->key) node->left = put_aux(node->left, value);
    else if(value > node->key) node->right = put_aux(node->right, value);
    else node->key = value;

    return node;
}

void put(BinTree *binTree, int value){
    
    Node *root = binTree->root;
    if(root == NULL) root = new_node(value);
    else root = put_aux(root, value);
}

