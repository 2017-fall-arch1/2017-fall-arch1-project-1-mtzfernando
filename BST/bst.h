#ifndef bst_h
#define bst_h
/*
  Author: Fernando Martinez
  Header file for the program
*/
  
typedef struct node_s{
  char* name;
  struct node_s* lNode;
  struct node_s* rNode; 
} node;

typedef struct bst{
  node* root;
} Bst;

Bst* newBst();
node* newNode(char* name);
void insertNode(Bst* bst, char* name);
node* deleteNode(node* node, char* name);
void printBst(node* node);
int searchNode(node* node, char* name);

#endif
