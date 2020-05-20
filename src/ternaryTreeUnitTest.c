/** ternaryTreeUnitTest.c
* ===========================================================
* Name: Christopher Chwa and Jim Wang, 18 May, 2020
* Section: T6 & T2A
* Project: PEX4 - Spell Checker
* Purpose: alternate driver function to test balanced insert,
 * tree insert, tree traversal, and spellcheck functionality.
 * Will need to include in CMakeLists.txt to work
* ===========================================================
*/

#include "dFuncts.h"

int main(void) {

    char dictFile[50];
    char testFile[50];

    // TEST 1
    printf("\nTEST 1\n");
    Node *root = NULL;

    strcpy(dictFile, "../unit-tests/dict1.txt");
    strcpy(testFile, "../unit-tests/test1.txt");

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

    printf("\nBalanced Tree Insertion Test:\n");
    makeTreeTest(&root, completeDictionary, 0, dictWC); // put array into tree
    // individual test cases

    printf("\nTree Insertion Test:\n");
    traverseTree(root);

    printf("\nSpellcheck Test:\n");
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

    // TEST 2
    printf("\nTEST 2\n");
    root = NULL;

    strcpy(dictFile, "../unit-tests/dict2.txt");
    strcpy(testFile, "../unit-tests/test2.txt");

    printf("Function Arguments (relative paths):\nDictionary File Path: %s\nTest File Path: %s\n",
           dictFile, testFile);

    dictWC = countWords(dictFile); // number of words
    testWC = countWords(testFile);


    completeDictionary = malloc(dictWC * sizeof(char*));
    for (int i = 0; i < dictWC; i++)
        completeDictionary[i] = malloc(20 * sizeof(char));

    completeTest = malloc(testWC * sizeof(char*));
    for (int i = 0; i < testWC; i++)
        completeTest[i] = malloc(20 * sizeof(char));

    loadFile(dictFile, dictWC, completeDictionary); // put .txt into array
    loadFile(testFile, testWC, completeTest);

    printf("\nBalanced Tree Insertion Test:\n");
    makeTreeTest(&root, completeDictionary, 0, dictWC); // put array into tree
    // individual test cases

    printf("\nTree Insertion Test:\n");
    traverseTree(root);

    printf("\nSpellcheck Test:\n");
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

    // TEST 3
    printf("\nTEST 3\n");
    root = NULL;
    strcpy(dictFile, "../unit-tests/dict3.txt");
    strcpy(testFile, "../unit-tests/test3.txt");

    printf("Function Arguments (relative paths):\nDictionary File Path: %s\nTest File Path: %s\n",
           dictFile, testFile);

    dictWC = countWords(dictFile); // number of words
    testWC = countWords(testFile);


    completeDictionary = malloc(dictWC * sizeof(char*));
    for (int i = 0; i < dictWC; i++)
        completeDictionary[i] = malloc(20 * sizeof(char));

    completeTest = malloc(testWC * sizeof(char*));
    for (int i = 0; i < testWC; i++)
        completeTest[i] = malloc(20 * sizeof(char));

    loadFile(dictFile, dictWC, completeDictionary); // put .txt into array
    loadFile(testFile, testWC, completeTest);

    printf("\nBalanced Tree Insertion Test:\n");
    makeTreeTest(&root, completeDictionary, 0, dictWC); // put array into tree
    // individual test cases

    printf("\nTree Insertion Test:\n");
    traverseTree(root);

    printf("\nSpellcheck Test:\n");
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