/** PEX4.c
* ===========================================================
* Name: Christopher Chwa and Jim Wang, 18 May, 2020
* Section: T6 & T2A
* Project: PEX4 - Spell Checker
* Purpose: Use a ternary tree to implement a spell checker.
* Documentation: Referenced geeks for geeks implementation
 * of a ternary tree and referenced course provided binary
 * search algorithm for the makeTree function.
* ===========================================================
*/

#include "dFuncts.h"

int main(int argc, char* argv[]) // if program doesn't run, reload CMakeLists.txt
{
    Node *root = NULL;

    char dictFile[50];
    char testFile[50];

    strcpy(dictFile, argv[1]);
    strcpy(testFile, argv[2]);

    printf("Function Arguments (relative paths):\nDictionary File Path: %s\nTest File Path: %s\n",
            dictFile, testFile);

    int dictWC = countWords(dictFile); // number of words
    int testWC = countWords(testFile);


    char** completeDictionary = malloc(dictWC * sizeof(char*));
    for (int i = 0; i < dictWC; i++)
        completeDictionary[i] = malloc(20 * sizeof(char));

    char** completeTest = malloc(testWC * sizeof(char*));
    for (int i = 0; i < testWC; i++)
        completeTest[i] = malloc(20 * sizeof(char));

    loadFile(dictFile, dictWC, completeDictionary); // put .txt into array
    loadFile(testFile, testWC, completeTest);

    makeTree(&root, completeDictionary, 0, dictWC); // put array into tree

    printf("\nSpellchecking: \n");
    for (int i = 0; i < testWC; i++) {
        printf("%s: ", completeTest[i]);
        searchTree(root, completeTest[i]) ? printf("Correct\n") : printf("Incorrect\n");
    }

    // free pointer arrays
    for (int i = 0; i < dictWC; i++)
        free(completeDictionary[i]);
    free(completeDictionary);

    for (int i = 0; i < testWC; i++)
        free(completeTest[i]);
    free(completeTest);


    // delete tree
    deleteTree(root);

    return 0;
}