// Including datatype so we can use it's functions and variables
#include "datatype.h"

// Defining structers and functions for implementation
typedef struct BStree_node {
Key key;
Data data;
struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;

BStree bstree_ini(void);
BStree_node *new_node(Key key, Data data);
void bstree_insert(BStree bst, Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traverse(BStree bst);
void bstree_free(BStree bst);
