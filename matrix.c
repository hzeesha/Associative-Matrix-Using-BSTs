// Importing necessary packages
#include <stdio.h>
#include "matrix.h"

// Creating a matrix
Matrix matrix_construction(void){
  Matrix matrix;
  // Creating matrix using our binary search tree initialization
  matrix = bstree_ini();
  // Returning matrix
  return matrix;
}

// Function to check if the location (index1, index2) is defined in matrix m
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2){
  // Inititalizing a key for usage
  Key key = key_ini();
  key_set(key, index1, index2);
  // Creating a data object with the search of the key in the BST
  Data result = bstree_search(m, key);
  // Returning the correct result
  if(result == NULL){
    return 0;
  }
  return 1;
}

// If the location is defined, then we return a pointer to the associated value
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2){
  // Inititalizing a key
  Key key = key_ini();
  key_set(key, index1, index2);
  // Creating a data object with the search of the key in the BST
  Data result = bstree_search(m, key);
  // Returning null if the result is null
  if(result == NULL){
    return NULL;
  }
  // Returnign a pointer to the result if it's not 
  Value* value = result;
  return value;
}

// Function to assign value to matrix at location, if it's full, it's overwritten
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value){
  // Initializing the key and Data objects based on parameters
  Key key = key_ini();
  key_set(key, index1, index2);
  Data data = data_ini();
  data_set(data, value);
  // Searching through the tree and storing the result
  Data result = bstree_search(m, key);
  // If the node doensn't exist, we add it
  if(result == NULL){
    bstree_insert(m, key, data);
  }
  // If it does exist, we adjust it's value
  else{
    *result = value;
  }
}

// Traversing through the matrix
void matrix_list(Matrix m){
  bstree_traverse(m);
}

// Freeing space
void matrix_destruction(Matrix m){
  bstree_free(m);
}
