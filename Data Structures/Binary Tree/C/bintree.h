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

// Creates a new binary tree
BinTree *new_bintree();
// Add a new node into the tree if not inserted already
void put(BinTree *binTree, int value);
// Inorder(Left/Root/Right) print of the binary tree
void print_inorder(Node *root);
// Preorder(Root/Left/Right) print of the binary tree
void print_preorder(Node *root);
// Postorder(Left/Right/Root)
void print_postorder(Node *root);
// Prints all nodes values in increasing order
void print_increase_order(Node *root);
// Returns the min value in the binary tree
int min_value(Node *root);
// Returns the max value in the binary tree
int max_value(Node *root);
// Checks if value exists on the binary tree
int check_value(Node *root, int value);
// Returns the node holding a given value
Node *get_node(Node *root, int value);
// Returns the parent node from a given value
Node *get_parent(Node *root, int value);
// Returns the sucessor of a given node
Node *get_sucessor(Node *binTreeRoot, Node *node);
// Returns the total node count in the tree
int node_count(Node *root);


#endif