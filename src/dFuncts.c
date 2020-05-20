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


//Where the words are actually read in and stored
void loadDictionary(char *fileName, int numWords, singleWord completeDictionary[])
{
    FILE *dictionary = fopen(fileName, "r");
    if (dictionary == NULL) {
        printf("Error opening data file.\n");
        exit(0);
    }
    int i = 0;
    while (i < numWords)
    {
        completeDictionary[i].numInDictionary = i+1;
        fscanf(dictionary, "%s", completeDictionary[i].word);
        i++;
    }
}

void makeTree(Node **dictionaryTree, singleWord completeDictionary[], int wc)
{
    int middle = wc/2; // wc is one more than the highest index num
    int leftSide = 0;
    int rightSide = 0;

    while(wc > 0){
        insert(dictionaryTree, completeDictionary[wc-1].word);
        wc--;
    }
    // makeTree(&dictionaryTree, completeDictionary,  middle/2);
}