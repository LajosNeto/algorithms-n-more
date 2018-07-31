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
    printf("%d ", node->key);
    print_inorder(node->right);
}

void print_preorder(Node *node){

    if(node == NULL){
        return;
    }
    printf("%d ", node->key);
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_postorder(Node *node){
    
    if(node == NULL){
        return;
    }
    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d ", node->key);
}

void print_increase_order(Node *root){
    print_inorder(root);
}

int min_value(Node *root){
    int min = 0;
    if(root->left == NULL){
        return root->key;
    }
    min = min_value(root->left);
    return min;
}

int max_value(Node *root){
    int max = 0;
    if(root->right == NULL){
        return root->key;
    }
    max = max_value(root->right);
    return max;
}

int check_value(Node *root, int value){
    
    if(root == NULL){
        return 0;
    }
    if(value > root->key) return check_value(root->right, value);
    else if(value < root->key) return check_value(root->left, value);
    return 1;
}

Node *get_parent(Node *root, int value){

    if(root->key == value) return root;
    if(root->left == NULL && root->right == NULL) return NULL;
    if(root->left && root->left->key == value) return root;
    if(root->right && root->right->key == value) return root;
    if(root->right && value > root->key) return get_parent(root->right, value);
    if(root->left && value < root->key) return get_parent(root->left, value);
}