// Including necessary packages
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bstree.h"

// Initializing a binary search tree
BStree bstree_ini(void){
  BStree bst;
  // Allocating a node pointer for the tree
  bst = (BStree)malloc(sizeof(BStree_node*));
  // Setting the pointer to the tree to null
  *bst = NULL;
  // Returning the tree
  return bst;
}

// New node helper function for potential later usage
BStree_node *new_node(Key key, Data data){
  // Allocatin memory for the node
  BStree_node * newNode = (BStree_node *)malloc(sizeof(BStree_node));
  // Setting variables to their appropriate values
  newNode->key = key;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Function to insert a node into the tree 
void bstree_insert(BStree bst, Key key, Data data){
  // New node
  BStree_node* node = new_node(key, data);
  // Setting value for current root (this changes as we traverse the tree)
  BStree_node* root = *bst;
  // If the current location is null we add the node there
  if(root == NULL){
    *bst = node;
  }
  // Otherwise, we traverse the tree, placing the node in the correct location
  else{
    // Comparing the keys
    int result = key_comp(key, root->key);
    // if the key is less than we traverse the left
    if(result == -1){
      bstree_insert(&(root->left), key, data);
    }
    // Otherwise, we traverse the right
    else if(result == 1){
      bstree_insert(&(root->right), key, data);
    }
    // Doing nothing if the node already exists
    else{
      return;
    }
  }
}

// Searching the tree for a node
Data bstree_search(BStree bst, Key key){
  // Setting the root/current node
  BStree_node* root = *bst;
  // If not found we return null
  if(root == NULL){
    return NULL;
  }
  // Checking if the node matches the current node
  int comp = key_comp(key, root->key);
  if(comp == 0){
    // Returning the data if it matches
    return root->data;
  }
  // If it doesn't match we traverse the tree and recursively check 
  else{
    int result = key_comp(key, root->key);
    if(result == -1){
      return bstree_search(&(root->left), key);
    }
    else if(result == 1){
      return bstree_search(&(root->right), key);
    }
  }
  // Returning NULL if not found
  return NULL;
}

// Traversing the tree
void bstree_traverse(BStree bst){
  // Setting the root/current node
  BStree_node* root = *bst;
  // If the current node is null the recursive function ends (base case)
  if(root == NULL){
    return;
  }
  // Traversing left side
  bstree_traverse(&(root->left));
  // Prinitng node
  printf("%-10d %-25s %f\n", root->key->key2, root->key->key1, *root->data);
  // Traversing the right side
  bstree_traverse(&(root->right));
}

// Free function, freeing the nodes in our tree
void bstree_free(BStree bst){
  BStree_node* root = *bst;
  // Base case
  if(root == NULL){
    return;
  }
  // Traversing left side, right side, and freeing the root node
  bstree_free(&(root->left));
  bstree_free(&(root->right));
  free(root);
}
