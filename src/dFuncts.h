/** dFuncts.h
* ===========================================================
* Name: Christopher Chwa and Jim Wang, 18 May, 2020
* Section: T6 & T2A
* Project: PEX4 - Spell Checker
* Purpose: Implement functions for loading dictionary into
 * a ternary tree while keeping it balanced.
* ===========================================================
*/

#ifndef PEX_4_CHWA_WANG_DFUNCTS_H
#define PEX_4_CHWA_WANG_DFUNCTS_H

#include "ternaryTree.h"

/** -------------------------------------------------------------------
 * Counts the words in the file.
 * @param fileName for the text file to count words in
 * @return number of total words in the file
  -------------------------------------------------------------------*/
int countWords(char *fileName);

/** -------------------------------------------------------------------
 * Loads the words from file into a dynamically allocated array.
 * @param File name to load the words in from
 * @return nothing
  -------------------------------------------------------------------*/
void loadFile(char *fileName, int numWords, char** completeDictionary);

/** -------------------------------------------------------------------
 * Recursively loads words from array into ternary tree
 * Ensures tree remains balanced.
 * @param Tree, dictionary, and the indexes
 * @return nothing
  -------------------------------------------------------------------*/
void makeTree(Node **dictionaryTree, char** completeDictionary, int left, int right);

/** -------------------------------------------------------------------
 * Recursively loads words from array into ternary array and prints what
 * is being inserted to ensure balance.
 * @param Tree, dictionary, and the indexes
 * @return nothing
  -------------------------------------------------------------------*/
void makeTreeTest(Node **dictionaryTree, char** completeDictionary, int left, int right);
#endif //PEX_4_CHWA_WANG_DFUNCTS_H
