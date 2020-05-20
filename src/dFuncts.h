#ifndef PEX_4_CHWA_WANG_DFUNCTS_H
#define PEX_4_CHWA_WANG_DFUNCTS_H

#include "ternaryTree.h"

typedef struct {
    char word[100];
    int numInDictionary;
} singleWord;

int countWords(char *fileName);

void loadDictionary(char *fileName, int numWords, singleWord completeDictionary[]);

void makeTree(Node **dictionaryTree, singleWord completeDictionary[], int left, int right);


#endif //PEX_4_CHWA_WANG_DFUNCTS_H
