#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
/*
  Author: Fernando Martinez
  Main method runs the interface.
*/
int main(){
  Bst* bst;
  int key;
  char name[25];
  FILE* fp;

  key = 0;
  bst = newBst();
  while(key != -1){
    printf("Enter a 1 to add a name.\n");
    printf("Enter a 2 to delete a name.\n");
    printf("Enter a 3 to print the list of employees.\n");
    printf("Enter a -1 to end the program\n");
    scanf("%d", &key);
    switch(key){
    case 1:
      printf("Enter name of employee:");
      scanf("%s", name);      
      insertNode(bst, name);
      printf("** %p **\n", bst);
      break;
    case 2:
      break;
    case 3:
      printBst(bst->root);
      break;
    case -1:
      break;
    default:
      puts("Invalid choice");
    }
  }
  /* fp = fopen("test.txt", "r");
  while(!feof(fp)){
    fgets(name, 50, fp);
    root = insertNode(root, name);
  }
  fclose(fp);
  do{
    printf("Enter:\n");
    scanf("%s", &name);
    printf("%s\n", name);
    root = insertNode(root, name);
    printBst(root);
  }
  while(strcmp("0", name) != 0);

  insertNode(bst, "Fer");
  insertNode(bst, "Eric");
  printBst(bst->root);
  insertNode(bst, "Gerardo");
  printf("The BST:\n");
  printBst(bst->root);
  root = deleteNode(bst->root, "Fer");
  printf("BST after deleting Fer:\n");
  printBst(bst->root);
  printf("New root %s\n", bst->root->name);*/
  return 0;
}
