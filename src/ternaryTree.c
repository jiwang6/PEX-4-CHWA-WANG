#include "ternaryTree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Node* newNode(char data){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->center = temp->right = NULL;
    return temp;
}

void insertTool(Node** currNode, char *word)
{
    // Base Case: Tree is empty
    if (!(*currNode))
        *currNode = newNode(*word);

    // If current character of word is smaller than currNode's character,
    // then insertTool this word in left subtree of currNode
    if (*word < (*currNode)->data)
        insertTool(&((*currNode)->left), word);

    // If current character of word is greater than currNode's character,
    // then insertTool this word in right subtree of currNode
    else if (*word > (*currNode)->data)
        insertTool(&((*currNode)->right), word);

    // If current character of word is same as currNode's character,
    else
    {
        if (*(word+1))
            insertTool(&((*currNode)->center), word + 1);

        // the last character of the word
        else {
            if ((*currNode)->center) {
                if ((*currNode)->center->data == '\0') // repeated input
                    return;
                (*currNode)->center->left = newNode(*word);
                (*currNode)->center->left->data = '\0';
            } else {
                (*currNode)->center = newNode(*word);
                (*currNode)->center->data = '\0';
            }
        }
    }
}

void insert(Node** currNode, char *word) {
    printf("Inserting %s\n", word);
    insertTool(currNode, word);
}

void traverseTreeTool(Node* currNode, char* buffer, int depth)
{
    if (currNode)
    {
        // First traverse the left subtree
        traverseTreeTool(currNode->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = currNode->data;

        if (currNode->data == '\0')
        {
            printf("%s\n", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTreeTool(currNode->center, buffer, depth + 1);

        // Finally Traverse the right subtree
        traverseTreeTool(currNode->right, buffer, depth);
    }
}

void traverseTree(Node* currNode)
{
    char buffer[MAX];
    traverseTreeTool(currNode, buffer, 0);
}

// Function to search a given word in TST
int searchTree(Node *currNode, char *word)
{
    if (!currNode)
        return 0;

    if (*word < (currNode)->data)
        return searchTree(currNode->left, word);

    else if (*word > (currNode)->data)
        return searchTree(currNode->right, word);

    else
    {
        if (*(word+1) == '\0') { // reach end of word input
            if (currNode->center->data == '\0') {
                return 1;
            } if(currNode->center->left) {
                if(currNode->center->left->data == '\0')
                    return 1;
            } else {
                return 0;
            }
        }
        return searchTree(currNode->center, word + 1);
    }
}

void deleteTree(Node* currNode) {
    if (currNode == NULL)
        return;

    deleteTree(currNode->left);
    deleteTree(currNode->center);
    deleteTree(currNode->right);

    // printf("deleting node: %c\n", currNode->data);
    free(currNode);
}