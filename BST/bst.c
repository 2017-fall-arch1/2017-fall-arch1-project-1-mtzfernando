#include <stdio.h>
#include <stdlib.h>

node* newNode(char* name){
  node* newNode = (node*) malloc(sizeof(node));
  newNode->name = name;
  newNode->lNode = NULL;
  newNode->rNode = NULL;
  return node;
}

node* insertNode(node* node, cahr* name){
  int cmp;

  if(node == NULL){
    node = newNode(name);
  }
  else{
    cmp = strcmp(node->name, name);
    if(cmp == 0){

    }
    else if(cmp > 0){

    }
    else if(cmp < 0){

    }
  }
  return node;
}
