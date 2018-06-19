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