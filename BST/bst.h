#ifndef bst_h
#define bst_h

typedef struct node_s{
  struct node_s* lNode;
  struct node_s* rNode;
  char* name;
} node;

typedef struct bst{
  node* root;
} bst;

bst* newBst();
node* newNode(char* name);
void insertNode(bst* bst, char* name);
void printBst(bst* bst);

#endif
