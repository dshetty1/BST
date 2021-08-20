//Author: Dhruv Shetty

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// Creates a new node on the bst and adds a word to it.
void add ( bst_node ** root, char * word ) {
    // Checks if word was entered
    if (word == NULL){
        return;
    }
    // Checks if tree is empty
    if (* root == NULL){
        * root = new_node(word);
        return;
    }
    // Checks if word is smaller than root. If so, attempt to place word as left node
    if (strcmp((* root)->data, word) > 0){
        if((* root)->left == NULL){
            (* root)->left = new_node(word);
        }
        else {
            add(&(* root)->left, word);
        }

    }
    // Checks if word is larger than root. If so, attempt to place word as right node
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

// Traverses the bst in an inorder pattern and prints the data element in each node.
void inorder ( bst_node * root ) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}

// Traverses bst to find smallest node (furthest left, on lowest row) and removes it.
char * removeSmallest (bst_node ** root){
    // Checks if root tree is empty
    if (* root == NULL)
        return NULL;

    char * min;
    bst_node * temp = * root;
    bst_node * parent = NULL;

    // Identifies smallest node
    while(temp->left != NULL) {
        parent = temp;
        temp = temp->left;
    }

    // Re-orient nodes to fit bst and return smallest node
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


// Traverses bst to find largest node (furthest right, on lowest row) and removes it.
char * removeLargest (  bst_node ** root ){
    // Checks if root tree is empty
    if (* root == NULL){
        return NULL;
    }

    char * largest;
    bst_node * temp = * root;
    bst_node * parent = NULL;

    // Identifies largest node
    while (temp->right != NULL){
        parent = temp;
        temp = temp->right;
    }

    // Re-orient nodes to fit bst and return largest node
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

// Constructor to create a new node.
bst_node * new_node(char * input){
    // Allocate space for new node
    bst_node * node = (bst_node*)malloc(sizeof(bst_node));

    node->data = input;
    node->right = NULL;
    node->left = NULL;
    return node;
}
