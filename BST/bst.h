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

Bst* newBst();                              /*Creates a new Binary Search Tree.*/
node* newNode(char* name);                 /*Creates a new node.*/
void insertNode(Bst* bst, char* name);     /*Inserts a new node into the BST.*/
node* deleteNode(node* node, char* name);  /*Deletes a node from the BST.*/
void printBst(node* node);                 /*Prints the BST inorder.*/
int searchNode(node* node, char* name);    /*Search for a node.*/
void run();                                /*Runs the whole program.*/
int isLowerCase(char c);                   /*Checks if a char is a lowercase.*/
int toUpperCase(char c);                   /*Converts lowercase chars into uppercase.*/
void convert(char* name);                   /*Starts the convertion of lowercase to uppercase.*/

#endif
