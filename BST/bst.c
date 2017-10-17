#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
/*
  Author: Fernando Martinez
  Refernces:
    www.geeksforgeeks.org
    Dr. Freudenthal's code on github.com
*/
node* newNode(char* name){
  node* newNode = (node*) malloc(sizeof(node));
  newNode->name = name;
  newNode->lNode = NULL;
  newNode->rNode = NULL;
  return newNode;
}

node* insertNode(node* node, char* name){

  if(node == NULL){
    node = newNode(name);
  }
  else if(strcmp(name, node->name) <= 0){
    node->lNode = insertNode(node->lNode, name);
  }
  else{
    node->rNode = insertNode(node->rNode, name);
  }
  return node;
}

node* deleteNode(node* node, char* name){
  struct node_s* tmp;
  
  if(node == NULL){
    return node;
  }
  if(strcmp(name, node->name) < 0){
    node->lNode = deleteNode(node->lNode, name);
  }
  else if(strcmp(name, node->name) > 0){
    node->rNode = deleteNode(node->rNode, name);
  }
  else{
    if(node->lNode == NULL){
      tmp = node->rNode;
      free(node);
      return tmp;
    }
    if(node->rNode == NULL){
      tmp = node->lNode;
      free(node);
      return tmp;
    }
    
    tmp = node->rNode;
    
    while(tmp->lNode != NULL){
      tmp = tmp->lNode;
    }
    node->name = tmp->name;
    node->rNode = deleteNode(node->rNode, tmp->name);
  }
  return node;
}

void printBst(node* node){
  if(node != NULL){
    printBst(node->lNode);
    printf("<%s>\n", node->name);
    printBst(node->rNode);
  }
}
