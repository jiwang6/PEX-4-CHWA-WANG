#include "dFuncts.h"

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
    return wordCount;
}


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
}

void makeTree(Node **dictionaryTree, char** completeDictionary, int left, int right)
{
    if(right == left)
        return;
    insert(dictionaryTree, completeDictionary[(left + (right - left) / 2)]); // algebra is hard
    makeTree(dictionaryTree, completeDictionary, left, left + (right - left)/2);
    makeTree(dictionaryTree, completeDictionary, 1 + left + (right - left)/2, right);
}

void makeTreeTest(Node **dictionaryTree, char** completeDictionary, int left, int right)
{
    if(right == left)
        return;
    insertTest(dictionaryTree, completeDictionary[(left + (right - left) / 2)]); // algebra is hard
    makeTreeTest(dictionaryTree, completeDictionary, left, left + (right - left)/2);
    makeTreeTest(dictionaryTree, completeDictionary, 1 + left + (right - left)/2, right);
}