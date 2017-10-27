#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
/*
  Author: Fernando Martinez
  Refernces:
    www.geeksforgeeks.org
    Dr. Freudenthal's code on github.com
    www.techcrashcourse.com
    C Primer Plus
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
    } else if(node->rNode == NULL){                             /*If the node has one child on the left*/
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
    printf("%s\n", node->name);
    printBst(node->rNode);
  }
}

/*Function to search for an employee. Searches inorder and recursively.*/
int searchNode(node* node, char* name){
  int flag = 0;                  /*Int used as a boolean to check if the employee is in the list*/

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

/*Function for running the whole program. Contains a loop for the input of the user. Also, contains the interface of the program.*/
void run(){
  Bst* bst;
  int key, flag;
  char name[25];
  FILE* fp;

  key = 0;
  bst = newBst();
  insertNode(bst, "FERNANDO");
  insertNode(bst, "HECTOR");
  insertNode(bst, "DAVID");
  insertNode(bst, "XAVIOR");
  insertNode(bst, "ALBERT");
  insertNode(bst, "YURI");
  insertNode(bst, "BRENDA");
  printf("The BST:\n");
  printBst(bst->root);
  
  while(key != -1){
    printf("Enter 1 to add a name: \n");
    printf("Enter 2 to delete a name: \n");
    printf("Enter 3 to print the list of employees:\n");
    printf("Enter 4 to search for an employee: \n");
    printf("Enter 5 to read from a file:\n");
    printf("Enter 6 to write to a file and add it to the list\n");
    printf("Enter a -1 to end the program\n");
    scanf("%d", &key);
    switch(key){
    case 1:
      printf("Enter name of employee: ");
      scanf("%s", name);
      convert(name);
      insertNode(bst, strdup(name));
      break;
    case 2:
      printf("Enter the name to be deleted: ");
      scanf("%s", name);
      convert(name);
      flag = searchNode(bst->root, name);
      if(flag == 1){
	deleteNode(bst->root, strdup(name));
	printf("The name %s was deleted from the list.\n", name);
      } else
	printf("Can not delete %s from the list due to not being in the list\n", name);
      break;
    case 3:
      printf("The list of employees:\n");
      printBst(bst->root);
      break;
    case 4:
      printf("Enter the name to search for: ");
      scanf("%s", name);
      convert(name);
      flag = searchNode(bst->root, name);
      if(flag == 1)
	printf("The employee %s is in the list.\n", name);
      else
	printf("The employe %s is NOT in the list.\n", name);
      break;
    case 5:
      fp = fopen("test.txt", "r");
      while(!feof(fp)){
	fscanf(fp, "%s", name);
	convert(name);
	insertNode(bst, strdup(name));
      }
      fclose(fp);
      break;
    case 6:
      fp = fopen("test.txt", "a");
      printf("Enter the name to write to the file: ");
      scanf("%s", name);
      convert(name);
      fprintf(fp, "%s\n", name);
      fclose(fp);
      insertNode(bst, strdup(name));
      break;
    case -1:
      printf("Exiting program\n");
      break;
    default:
      puts("Invalid choice\n");
    }
  }
}

/*Function to check if the iput char is a lowercase.*/
int isLowerCase(char c){
  if(c >= 'a' && c <= 'z')
    return 1;
  else
    return 0;
}

/*Function converts lowercases to uppercases.*/
int toUpperCase(char c){
  return c - 32;
}

/*Function takes care of the conversion of lowercase to uppercase.*/
void convert(char* name){
  int i;
  for(i = 0; name[i] != '\0'; i++){
    if(isLowerCase(name[i]))
      name[i] = toUpperCase(name[i]);
    else
      name[i] = name[i];
  }
  name[i] = '\0';
}
