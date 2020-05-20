/** ternaryTree.h
* ===========================================================
* Name: Christopher Chwa and Jim Wang, 18 May, 2020
* Section: T6 & T2A
* Project: PEX4 - Spell Checker
* Purpose: Implement ternary tree functionality
* ===========================================================
*/

#ifndef MYEXE_TERNARYTREE_H
#define MYEXE_TERNARYTREE_H

#define MAX 50

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// define tree node
typedef struct node
{
    char data;
    struct node* left;
    struct node* center;
    struct node* right;
} Node;

/** -------------------------------------------------------------------
 * Creates new node and loads data into node.
 * @param data, the word to be loaded into the node
 * @return node pointer to new node
  -------------------------------------------------------------------*/
Node* newNode(char data);

/** -------------------------------------------------------------------
 * Inserts a word into the tree, uses recursion.
 * @param currentNode and the word to insert
 * @return nothing
  -------------------------------------------------------------------*/
void insert(Node** currNode, char *word);

/** -------------------------------------------------------------------
 * Calls the insert function and prints the word being inserted.
 * @param Current node and the word to be inserted
 * @return nothing
  -------------------------------------------------------------------*/
void insertTest(Node** currNode, char *word);


/** -------------------------------------------------------------------
 * Does an in order traversal of the tree and prints the in order traversal. Uses recursion
 * @param The current node, buffer(holds the data of the node), and depth
 * @return nothing
  -------------------------------------------------------------------*/
void traverseTreeTool(Node* currNode, char* buffer, int depth);

/** -------------------------------------------------------------------
 * Creates output buffer and calls traverseTreeTool (see above) to fill
 * buffer.
 * @param Pointer to the current node.
 * @return nothing
  -------------------------------------------------------------------*/
void traverseTree(Node* currNode);

/** -------------------------------------------------------------------
 * Searches for the word in the ternary tree letter by letter.
 * Terminates when it gets to '\0' character. Uses recursion.
 * @param Current node and the word it is searching for.
 * @return returns 1 or 0, 1 if the word is found, 0 if it is not found aka spelled incorrectly
  -------------------------------------------------------------------*/
int searchTree(Node *currNode, char *word);

/** -------------------------------------------------------------------
 * Deletes the tree node by node.
 * @param Current node to delete. Tree is deleted when the node is
 * NULL, where all the nodes are deleted.
 * @return Nothing
  -------------------------------------------------------------------*/
void deleteTree(Node* currNode);

#endif //MYEXE_TERNARYTREE_H
