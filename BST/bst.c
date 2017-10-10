#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

bst* newBst(){
  bst* nBst = (bst*)malloc(sizeof(bst));
  nBst->root = 0;
  return nBst;
}

node* newNode(char* name){
  node* newNode = (node*) malloc(sizeof(node));
  newNode->name = name;
  newNode->lNode = NULL;
  newNode->rNode = NULL;
  return newNode;
}

void insertNode(bst* bst, char* name){
  node* node = newNode(name), *tmp;
  tmp = bst->root;
  int cmp;

  printf("**%s** **%s\n", tmp, bst->root);
  
  printf("Before if(bst->root = NULL) %s - %s\n", bst->root, name);
  if(bst->root == NULL){
    bst->root = node;
    printf("Inside if(bst->root = NULL) %s - %s\n", bst, name); 
  }
  else{
    cmp = strcmp(name, node->name);
    printf("Inside else %d\n", cmp);
    if(cmp == 0){
      printf("cmp = 0\n");
      while(tmp->lNode != NULL){
	tmp = tmp->lNode;
      }
      tmp->lNode = node;
    }
    else if(cmp > 0){
      printf("cmp > 0\n");
    }
    else if(cmp < 0){
      printf("cmp < 0\n");
    }
  }
}

void printBst(bst* bst){
  node* node;
  printf("Inside printBst before for loop %s\n", bst->root);
  for(node = bst->root; node; node = node->lNode){
    printf("<%s>\n", node->name);
  }
  printf("Inside printBst after for loop\n");
}
