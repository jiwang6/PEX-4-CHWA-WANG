/** dFuncts.c
* ===========================================================
* Name: Christopher Chwa and Jim Wang, 18 May, 2020
* Section: T6 & T2A
* Project: PEX4 - Spell Checker
* Purpose: Implement functions for loading dictionary into
 * a ternary tree while keeping it balanced.
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
 * Loads the words from file into a dynamically allocated array.
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
 * Recursively loads words from array into ternary tree
 * Ensures tree remains balanced.
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
 * Recursively loads words from array into ternary array and prints what
 * is being inserted to ensure balance.
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