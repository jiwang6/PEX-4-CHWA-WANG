//
// Created by C22Christopher.Chwa on 5/18/2020.
//

#ifndef MYEXE_TERNARYTREE_H
#define MYEXE_TERNARYTREE_H

typedef struct node
{
    char data;
    struct node* left;
    struct node* center;
    struct node* right;
} Node;

typedef struct
{
    Node* root;
} ternaryTree;




ternaryTree *createTree();


Node *traverseCenter(ternaryTree *Tree, Node *currentNode, char word[], int index);

void insert(ternaryTree *Tree, char word[]);

void insertRemaining(Node *currentNode, char word[], int index);

void printTree(ternaryTree *Tree);

#endif //MYEXE_TERNARYTREE_H
