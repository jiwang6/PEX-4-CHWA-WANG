#ifndef PEX_4_CHWA_WANG_DFUNCTS_H
#define PEX_4_CHWA_WANG_DFUNCTS_H

#include "ternaryTree.h"

int countWords(char *fileName);

void loadFile(char *fileName, int numWords, char** completeDictionary);

void makeTree(Node **dictionaryTree, char** completeDictionary, int left, int right);

void makeTreeTest(Node **dictionaryTree, char** completeDictionary, int left, int right);
#endif //PEX_4_CHWA_WANG_DFUNCTS_H
