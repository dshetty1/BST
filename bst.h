#ifndef BST_H_
#define BST_H_

// A node structure for use with the binary search tree
typedef struct  bst_node {
    char * data;
    struct bst_node * right;
    struct bst_node * left;
} bst_node ;


// Adds a value to the binary search tree
void add (bst_node ** root, char * word);


// Prints the values stored in the bst the output according to inorder traversal
void inorder (bst_node * root);

// Removes the node with the smallest value in the tree
char * removeSmallest (bst_node ** root);

// Removes the node with the largest value in the tree
char * removeLargest (bst_node ** root);


// Declaration for the new_node constructor
struct bst_node* new_node(char * input);



#endif
