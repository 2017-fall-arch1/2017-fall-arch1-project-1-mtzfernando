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
/*Creates a BST.*/
Bst* newBst(){
  Bst* nBst = (Bst*)malloc(sizeof(Bst));
  nBst->root = NULL;
  return nBst;
}

/*Create a new Node for the bst*/
node* newNode(char* name){
  node* newNode;
  newNode = (node*) malloc(sizeof(node));
  if(newNode != NULL){
    newNode->name = name;
    newNode->lNode = NULL;
    newNode->rNode = NULL;
  }
  return newNode;
}

/*Helper method to add the node in the correct place.*/
static void addNode(node* newNode, node* root){
  /*Compare the current node name to the node being created.*/
  if(strcmp(newNode->name, root->name) <= 0){                  
    if(root->lNode == NULL)
      root->lNode = newNode;
    else
      addNode(newNode, root->lNode);
  } else{
    if(root->rNode == NULL)
      root->rNode = newNode;
    else
      addNode(newNode, root->rNode);
  }
}

/*Insert a new node into the bst*/
void insertNode(Bst* bst, char* name){
  node* node;
  node = newNode(name);
  if(bst->root == NULL){
    bst->root = node;
  } else{
    addNode(node, bst->root);
  }
}

/*Delete a node from the bst*/
node* deleteNode(node* node, char* name){
  struct node_s* tmp;                                    /*Temporary node to traverse the bst*/
  
  if(node == NULL){                                      /*If the node is null return the node*/
    return node;
  }
  if(strcmp(name, node->name) < 0){                      /*Traverse the bst to the left*/
    node->lNode = deleteNode(node->lNode, name);
  } else if(strcmp(name, node->name) > 0){                 /*Traverse the bst to the right*/
    node->rNode = deleteNode(node->rNode, name);
  } else{                                                  /*The node matched to the one to be deleted*/
    if(node->lNode == NULL){                             /*If the node has one child on the right*/
      tmp = node->rNode;
      free(node);
      return tmp;
    } else if(node->rNode == NULL){                             /*If the node has one child on the right*/
      tmp = node->lNode;
      free(node);
      return tmp;
    }
    /*If the node has two child*/
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

int searchNode(node* node, char* name){
  int flag = 0;

  if(node == NULL)
    return 0;
  if(strcmp(name, node->name) == 0)
    return 1;
  else if(strcmp(name, node->name) < 0)
    flag = searchNode(node->lNode, name);
  else
    flag = searchNode(node->rNode, name);

  return flag;
}
