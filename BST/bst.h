#ifndef bst_h
#define bst_h

typedef struct node_s{
  struct node_s* lNode;
  struct node_s* rNode;
  char* name;
} node;

node* newNode(char* name);
node* insertNode(node* node, char* name);
node* deleteNode(node* node, char* name);
void printBst(node* node);

#endif
