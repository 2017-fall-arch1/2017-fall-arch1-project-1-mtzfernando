#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
/*
  Author: Fernando Martinez
  Main method runs the interface.
*/
int main(){
  node* root = NULL;
  int key;
  char name[50];
  char* n;
  FILE* fp;
  /*
  fp = fopen("test.txt", "r");
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
    
  while(key != -1){
    printf("Enter a 1 to add a name.\n");
    printf("Enter a 2 to delete a name.\n");
    printf("Enter a 3 to print the list of employees.\n");
    printf("Enter a -1 to end the program\n");
    scanf("%d", &key);
    if(key == 1){
      key = 0;
      while(strcmp("0", name) != 0){
	printf("Enter the name to add or enter 0 to exit:\n");
	scanf("%s", name);
	n = name;
	printf("name = %s\n", name);
	root = insertNode(root, name);
	printBst(root);
	
	printf("%s//\n", root->name);
	}
    }
    if(key ==2){
      key = 0;
      while(key == 0){
	printf("Enter the name to delete or enter 1 to exit:\n");
	scanf("%s", name);
	root = deleteNode(root, name);
	key = atoi(name);
      }
    }
    if(key == 3){
      printBst(root);
      printf("case 3\n");
    }
    }*/
  root = insertNode(root, "Gerardo");
  root = insertNode(root, "Javier");
  root = insertNode(root, "David");
  root = insertNode(root, "Brenda");
  root = insertNode(root, "Fernando");
  root = insertNode(root, "Angel");
  root = insertNode(root, "Eric");
  root = insertNode(root, "Carlos");
  printf("The BST:\n");
  printBst(root);
  root = deleteNode(root, "Fernando");
  printf("BST after deleting Fernando:\n");
  printBst(root);
  return 0;
}
