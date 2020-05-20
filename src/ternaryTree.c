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

void insert(Node** currNode, char *word)
{
    if (!(*currNode)) // base case: empty tree
        *currNode = newNode(*word);

    if (*word < (*currNode)->data) // if char < currNode, left subtree
        insert(&((*currNode)->left), word);

    else if (*word > (*currNode)->data) // if char > currNode, right subtree
        insert(&((*currNode)->right), word);

    else // if char == currNode
    {
        if (*(word+1)) // if there is a char after currNode, center
            insert(&((*currNode)->center), word + 1);

        else { // last char in word
            if ((*currNode)->center) { // if there's more nodes in center branch
                if ((*currNode)->center->data == '\0') // repeated input
                    return;
                (*currNode)->center->left = newNode(*word); // create node left, end word early
                (*currNode)->center->left->data = '\0';
            } else {
                (*currNode)->center = newNode(*word); // create node under, end word
                (*currNode)->center->data = '\0';
            }
        }
    }
}

void insertTest(Node** currNode, char *word) { // prints insert order before inserting
    printf("Inserting %s\n", word);
    insert(currNode, word);
}

void traverseTreeTool(Node* currNode, char* buffer, int depth)
{
    if (currNode)
    {
        traverseTreeTool(currNode->left, buffer, depth); // traverse left subtree

        buffer[depth] = currNode->data; // store char from node

        if (currNode->data == '\0')
        {
            printf("%s\n", buffer);
        }

        traverseTreeTool(currNode->center, buffer, depth + 1); // traverse middle subtree

        traverseTreeTool(currNode->right, buffer, depth); // traverse right subtree
    }
}

void traverseTree(Node* currNode)
{
    char buffer[MAX];
    traverseTreeTool(currNode, buffer, 0);
}

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
            if (currNode->center->data == '\0') { // if null end
                return 1;
            } if (currNode->center->left) { // if there is a left node
                if(currNode->center->left->data == '\0') // if that left node is null end
                    return 1;
            } else { // word not found
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

    free(currNode);
}