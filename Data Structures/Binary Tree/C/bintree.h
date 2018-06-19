/** @file bintree.h
* 
* @brief Binary Tree implementation
*
*@author Lajos Onodi Neto
*/

#ifndef PROJECT_BINTREE_H
#define PROJECT_BINTREE_H

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinTree{
    Node *root;
} BinTree;

BinTree *new_bintree();

#endif