#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
  node* root = NULL;
  root = insertNode(root, "G");
  root = insertNode(root, "K");
  root = insertNode(root, "D");
  root = insertNode(root, "B");
  root = insertNode(root, "F");
  root = insertNode(root, "A");
  root = insertNode(root, "E");
  root = insertNode(root, "C");
  printBst(root);
  root = deleteNode(root, "F");
  printBst(root);

  return 0;
}
