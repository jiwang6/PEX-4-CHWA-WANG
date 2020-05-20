//
// Created by C2C Chwa and C2C Wang.
//


/** PEX4.c
* ===========================================================
* Name: Christopher Chwa and Jim Wang, 18 May, 2020
* Section: T6 & T2A
* Project: PEX4 - Spell Checker
* Purpose: Use a ternary tree to implement a spell checker.
* Documentation: Referenced geeks for geeks implementation of a ternary tree and referenced course provided binary search
* Algorithm for the makeTree function.
* ===========================================================
*/

#include "dFuncts.h"



/** -------------------------------------------------------------------
 * Counts the words in the file.
 * @param fileName for the text file to count words in
 * @return number of total words in the file
  -------------------------------------------------------------------*/
int countWords(char *fileName)
{
    int wordCount = 0;
    FILE *dictionary = fopen(fileName, "r");
    if (dictionary == NULL) {
        printf("Error opening data file.\n");
        exit(0);
    }
    char buffer[100];
    while (!feof(dictionary))
    {
        fscanf(dictionary, "%s", buffer);
        wordCount++;
    }
    fclose(dictionary);
    return wordCount;
}



/** -------------------------------------------------------------------
 * Loads the words in to an array
 * @param File name to load the words in from
 * @return nothing
  -------------------------------------------------------------------*/
// Where the words are actually read in and stored
void loadFile(char *fileName, int numWords, char** completeDictionary)
{
    FILE *dictionary = fopen(fileName, "r");
    if (dictionary == NULL) {
        printf("Error opening data file.\n");
        exit(0);
    }
    int i = 0;
    while (i < numWords)
    {
        fscanf(dictionary, "%s", completeDictionary[i]);
        i++;
    }
    fclose(dictionary);
}


/** -------------------------------------------------------------------
 * Counts Makes the ternary tree using recursion
 * @param Tree, dictionary, and the indexes
 * @return nothing
  -------------------------------------------------------------------*/
void makeTree(Node **dictionaryTree, char** completeDictionary, int left, int right)
{
    if(right == left)
        return;
    insert(dictionaryTree, completeDictionary[(left + (right - left) / 2)]); // algebra is hard
    makeTree(dictionaryTree, completeDictionary, left, left + (right - left)/2);
    makeTree(dictionaryTree, completeDictionary, 1 + left + (right - left)/2, right);
}


/** -------------------------------------------------------------------
 * Same thing as above
 * @param Tree, dictionary, and the indexes
 * @return nothing
  -------------------------------------------------------------------*/
void makeTreeTest(Node **dictionaryTree, char** completeDictionary, int left, int right)
{
    if(right == left)
        return;
    insertTest(dictionaryTree, completeDictionary[(left + (right - left) / 2)]); // algebra is hard
    makeTreeTest(dictionaryTree, completeDictionary, left, left + (right - left)/2);
    makeTreeTest(dictionaryTree, completeDictionary, 1 + left + (right - left)/2, right);
}