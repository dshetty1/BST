//Author: Dhruv Shetty

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/*
 * Creates a new node on the bst and adds a word to it.
 * Parameters: Bst root node, Word to add
 * Return value: none
*/
void add ( bst_node ** root, char * word ) {
    if (word == NULL){
        return;
    }

    if (* root == NULL){
        * root = new_node(word);
        return;
    }

    if (strcmp((* root)->data, word) > 0){

        if((* root)->left == NULL){
            (* root)->left = new_node(word);
        }
        else {
            add(&(* root)->left, word);
        }

    }

    else if(strcmp((* root)->data, word) < 0){
        if((* root)->right == NULL){
            (* root)->right = new_node(word);
        }
        else{
            add(&(* root)->right, word);
        }
    }
    return;
}

/*
 * Function to traverse the bst in the inorder pattern.
 * Prints the data element in each node.
 * Parameters: bst root node
 * Return value: none
*/
void inorder ( bst_node * root ) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}


/*
 * Function to remove the smallest element from the bst.
 * Traverses bst to find smallest furthest left, on lowest row, and removes it.
 * Parameters: bst root node
 * Return value: the smallest element (char)
*/
char * removeSmallest (bst_node ** root){
    if (* root == NULL)
        return NULL;

    char * min;
    bst_node * temp = * root;
    bst_node * parent = NULL;

    while(temp->left != NULL) {
        parent = temp;
        temp = temp->left;
    }

    if(temp->right != NULL){
        if(temp == * root){
            min = temp->data;
            * temp = * temp->right;
            * root = temp;
            free(temp);
            temp = NULL;
            return min;
        }
        else {
            min = temp->data;
            temp = temp->right;
            temp->right = NULL;
            return min;
            }
    }
    else {
        if (temp == * root){
            min = temp->data;
            free(temp);
            temp = NULL;
            * root = NULL;
            return min;
        }
        else{
            min = temp->data;
            parent->left = NULL;
            free(temp);
            temp = NULL;
            return min;
        }
    }
}


/*
 * Function to remove the largest element from the bst.
 * Traverses bst to find largest furthest right, on lowest row, and removes it.
 * Parameters: bst root node
 * Return value: the largest element (char)
*/
char * removeLargest (  bst_node ** root ){
    if (* root == NULL){
        return NULL;
    }

    char * largest;
    bst_node * temp = * root;
    bst_node * parent = NULL;

    while (temp->right != NULL){
        parent = temp;
        temp = temp->right;
    }

    if (temp->left != NULL){
        if (temp == *root){
            largest = temp->data;
            * root = temp->left;
            free(temp);
            temp = NULL;
            return largest;
        }
        else{
            largest = temp->data;
            parent->right = temp->left;
            temp = NULL;
            return largest;
        }
    }
    else{
        if(temp == *root){
            largest = temp->data;
            free(temp);
            temp = NULL;
            *root = NULL;
            return largest;
        }
        else{
            largest = temp->data;
            parent->right = NULL;
            free(temp);
            temp = NULL;
            return largest;
        }
    }
}


/*
 * Constructer to create a new node.
 * Parameters: input to be added
 * Return value: the newly created bst_node
*/
bst_node * new_node(char * input){
    bst_node * node = (bst_node*)malloc(sizeof(bst_node));

    node->data = input;
    node->right = NULL;
    node->left = NULL;
    return node;
}