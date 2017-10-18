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
/*Create a new Node for the bst*/
node* newNode(char* name){
  node* newNode = (node*) malloc(sizeof(node));
  newNode->name = name;
  newNode->lNode = NULL;
  newNode->rNode = NULL;
  return newNode;
}

/*Insert a new node into the bst*/
node* insertNode(node* node, char* name){
  /*If the node is empty create the node*/
  if(node == NULL){
    node = newNode(name);
  }
  else if(strcmp(name, node->name) <= 0){                  /*Compare the current node name to the node being created.*/
    node->lNode = insertNode(node->lNode, name);
  }
  else{
    node->rNode = insertNode(node->rNode, name);
  }
  return node;
}

/*Delete a node from the bst*/
node* deleteNode(node* node, char* name){
  struct node_s* tmp;                                    /*Temporary node to traverse the bst*/
  
  if(node == NULL){                                      /*If the node is null return the node*/
    return node;
  }
  if(strcmp(name, node->name) < 0){                      /*Traverse the bst to the left*/
    node->lNode = deleteNode(node->lNode, name);
  }
  else if(strcmp(name, node->name) > 0){                 /*Traverse the bst to the right*/
    node->rNode = deleteNode(node->rNode, name);
  }
  else{                                                  /*The node matched to the one to be deleted*/
    if(node->lNode == NULL){                             /*If the node has one child on the right*/
      tmp = node->rNode;
      free(node);
      return tmp;
    }
    if(node->rNode == NULL){                             /*If the node has one child on the right*/
      tmp = node->lNode;
      free(node);
      return tmp;
    }
    /*The node has two child*/
    tmp = node->rNode;
    /*Find the smaller child on the right side*/
    while(tmp->lNode != NULL){
      tmp = tmp->lNode;
    }
    node->name = tmp->name;
    node->rNode = deleteNode(node->rNode, tmp->name);
  }
  return node;
}

/*Print the bst inorder*/
void printBst(node* node){
  if(node != NULL){
    printBst(node->lNode);
    printf("<%s>\n", node->name);
    printBst(node->rNode);
  }
}
