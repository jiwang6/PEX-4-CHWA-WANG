/** ternaryTree.c
* ===========================================================
* Name: Christopher Chwa and Jim Wang, 18 May, 2020
* Section: T6 & T2A
* Project: PEX4 - Spell Checker
* Purpose: Implement ternary tree functionality
* ===========================================================
*/

#include "ternaryTree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/** -------------------------------------------------------------------
 * Creates new node and loads data into node.
 * @param data, the word to be loaded into the node
 * @return node pointer to new node
  -------------------------------------------------------------------*/
Node* newNode(char data){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->center = temp->right = NULL;
    return temp;
}


/** -------------------------------------------------------------------
 * Inserts a word into the tree, uses recursion.
 * @param currentNode and the word to insert
 * @return nothing
  -------------------------------------------------------------------*/
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


/** -------------------------------------------------------------------
 * Calls the insert function and prints the word being inserted.
 * @param Current node and the word to be inserted
 * @return nothing
  -------------------------------------------------------------------*/
void insertTest(Node** currNode, char *word) { // prints insert order before inserting
    printf("Inserting %s\n", word);
    insert(currNode, word);
}


/** -------------------------------------------------------------------
 * Does an in order traversal of the tree and prints the in order traversal. Uses recursion
 * @param The current node, buffer(holds the data of the node), and depth
 * @return nothing
  -------------------------------------------------------------------*/
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


/** -------------------------------------------------------------------
 * Creates output buffer and calls traverseTreeTool (see above) to fill
 * buffer.
 * @param Pointer to the current node.
 * @return nothing
  -------------------------------------------------------------------*/
void traverseTree(Node* currNode)
{
    char buffer[MAX];
    traverseTreeTool(currNode, buffer, 0);
}


/** -------------------------------------------------------------------
 * Searches for the word in the ternary tree letter by letter.
 * Terminates when it gets to '\0' character. Uses recursion.
 * @param Current node and the word it is searching for.
 * @return returns 1 or 0, 1 if the word is found, 0 if it is not found aka spelled incorrectly
  -------------------------------------------------------------------*/
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


/** -------------------------------------------------------------------
 * Deletes the tree node by node.
 * @param Current node to delete. Tree is deleted when the node is
 * NULL, where all the nodes are deleted.
 * @return Nothing
  -------------------------------------------------------------------*/
void deleteTree(Node* currNode) {
    if (currNode == NULL)
        return;

    deleteTree(currNode->left);
    deleteTree(currNode->center);
    deleteTree(currNode->right);

    free(currNode);
}