//
// Created by C22Christopher.Chwa on 5/18/2020.
//

#include "ternaryTree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    char test[10] = "HELLO";
    ternaryTree *Tree = createTree();
    insert(Tree, test);
    char test2[10] = "FIRE";
    insert(Tree, test2);
    printTree(Tree);
    return 0;
}

ternaryTree *createTree()
{
    ternaryTree *Tree = malloc(sizeof(Tree));
    Tree->root = NULL;
    return Tree;
}

void insert(ternaryTree *Tree, char word[])
{
    if (Tree->root == NULL)
    {
        Node *newInsert = malloc(sizeof(Node));
        newInsert->data = word[0];
        newInsert->left = NULL;
        newInsert->right = NULL;
        newInsert->center = NULL;
        Tree->root = newInsert;
        free(newInsert);

        Node *currentNode = malloc(sizeof(Node));
        currentNode = Tree->root;

        int i = 1; //Set to 1 because already stored the first letter in the root
        insertRemaining(currentNode, word, i);
    }
    else // not an empty tree
    {
        Node *currentNode;
        currentNode = Tree->root;
        int i = 0;
        while (i < strlen(word))
        {
            if (word[i] == currentNode->data && currentNode->center != NULL)
            {
                currentNode = currentNode->center;
            }
            else if (word[i] < currentNode->data && currentNode->left == NULL) // insert rest of the word
            {
                // Insert the first letter of the word
                Node *newInsert = malloc(sizeof(Node));
                newInsert->data = word[i];
                newInsert->left = NULL;
                newInsert->right = NULL;
                newInsert->center = NULL;
                currentNode->left = newInsert;
                currentNode = currentNode->left;
                i++;
                free(newInsert);

                insertRemaining(currentNode, word, i);
                break;
            }
            else if (word[i] > currentNode->data && currentNode->right == NULL) // insert rest of the word
            {
                insertRemaining(currentNode, word, i);
                break;
            }
            else if (word[i] < currentNode->data && currentNode->left != NULL)
            {
                currentNode = currentNode->left;
            }
            else if (word[i] > currentNode->data && currentNode->right != NULL)
            {
                currentNode = currentNode->right;
            }
            i++;
        }
    }
}



Node *traverseCenter(ternaryTree *Tree, Node *currentNode, char word[], int index)
{
    while (word[index] == currentNode->data) // goes down as far as the next letter matches the data in the tree
    {
        currentNode = currentNode->center;
        index++;
    }
    return currentNode;
}

void insertRemaining(Node *currentNode, char word[], int index)
{
    while (word[index] != '\0')
    {
        Node *nextLetter = malloc(sizeof(Node));
        nextLetter->data = word[index];
        nextLetter->left = NULL;
        nextLetter->right = NULL;
        nextLetter->center = NULL;

        currentNode->center = nextLetter; //Insert all the way down for the word.
        currentNode = currentNode->center; //sets currentNode to the newly inserted node
        index++;
    }
}


void printTree(ternaryTree *Tree)
{
        Node *currentNode = malloc(sizeof(Node));
        currentNode = Tree->root;
        while(currentNode->data != '\0')
        {
            printf("%c\n", currentNode->data);
            currentNode = currentNode->center;
        }
        free(currentNode);
}

