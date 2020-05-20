#ifndef MYEXE_TERNARYTREE_H
#define MYEXE_TERNARYTREE_H

#define MAX 50

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// define tst node
typedef struct node
{
    char data;
    struct node* left;
    struct node* center;
    struct node* right;
} Node;

Node* newNode(char data);
void insertTool(Node** currNode, char *word);
void insert(Node** currNode, char *word);

void traverseTreeTool(Node* currNode, char* buffer, int depth);
void traverseTree(Node* currNode);
int searchTree(Node *currNode, char *word);

#endif //MYEXE_TERNARYTREE_H
