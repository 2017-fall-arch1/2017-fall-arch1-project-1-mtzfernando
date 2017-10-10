#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
  bst* root = newBst();
  insertNode(root, "Fernando");
  insertNode(root, "Eric");
  insertNode(root, "David");
  printBst(root);

  return 0;
}
