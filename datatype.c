#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datatype.h"

// Initializing key
Key key_ini(){
  // Using malloc to allocate the right amount of memory
  Key key = (Key)malloc(sizeof(Key));
  return key;
}

// Setting the key when given key1 and key2
void key_set(Key key, Key1 key1, Key2 key2){
  // Allocating memory again because key1 is a char*
  key->key1 = (char * )malloc(strlen(key1) + 1);
  // Copying the string
  strcpy(key->key1, key1);
  key->key2 = key2;
}


// Key comparison
int key_comp(Key key1, Key key2){
  // Using strcmp to compare the strings to test for equality
  int result;
  result = strcmp(key1->key1, key2->key1);
  // If str1 is greater return 1
  if(result > 0){
    result = 1;
  }
  // If str2 is greater return -1
  if(result < 0) {
    result = -1;
  }
  // If both strings are the same we test key2
  if (result == 0){
    int num1 = key1->key2;
    int num2 = key2->key2;
    // Returning a -1 if key2 is greater, 1 if key1 is greater, 0 if they're equal
    if (num1 < num2){
      result = -1;
    }
    else if (num1 == num2){
      result = 0;
    }
    else{
      result = 1;
    }
  }
  return result;
}

// Printing the keys in order 
void key_print1(Key key){
  printf("%-30s %-5d", key->key1, key->key2);
}

// Printing the keys in reverse order 
void key_print2(Key key){
  printf("%-5d %-30s", key->key2, key->key1);
}

// Freeing the key
void key_free(Key key){
  free(key);
}

// Initializing Data which is a float*
Data data_ini(){
  Data data = (float *)malloc(sizeof(float));
}

// Setting the data when given an integer
void data_set(Data data, float intdata){
  *data = intdata;
}

// Printing data
void data_print(Data data){
  printf("data: %f", *data);
}

// Freeing data
void data_free(Data data){
  free(data);
}
