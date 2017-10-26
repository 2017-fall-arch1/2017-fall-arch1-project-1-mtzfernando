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
  node* node;
  int key;
  char name[25];
  FILE* fp;

  key = 0;
  bst = newBst();

  
  insertNode(bst, "F");
  insertNode(bst, "H");
  insertNode(bst, "D");
  insertNode(bst, "Z");
  insertNode(bst, "A");
  insertNode(bst, "Y");
  insertNode(bst, "B");
  printf("The BST:\n");
  printBst(bst->root);
  deleteNode(bst->root, "A");
  printf("The BST after:\n");
  printBst(bst->root);
  
  while(key != -1){
    printf("Enter a 1 to add a name.\n");
    printf("Enter a 2 to delete a name.\n");
    printf("Enter a 3 to print the list of employees.\n");
    printf("Enter a -1 to end the program\n");
    scanf("%d", &key);
    switch(key){
    case 1:
      printf("Enter name of employee: ");
      scanf("%s", name);      
      insertNode(bst, strdup(name));
      break;
    case 2:
      printf("Enter the name to be deleted: ");
      scanf("%s", name);
      node = deleteNode(bst->root, strdup(name));
      printf("The name %s was deleted from the BST.\n");
      break;
    case 3:
      printBst(bst->root);
      break;
    case -1:
      printf("The program is closing!\n");
      break;
    default:
      puts("Invalid choice\n");
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
  while(strcmp("0", name) != 0);*/
  
  return 0;
}
