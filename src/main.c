#include <stdio.h>
#include "main.h"


int main() {
    printf("Hello, World!\n");


    return 0;
}


int loadDictionary(char *fileName)
{
    char word[10000];
    FILE *dictionary = NULL;
    dictionary = fopen(fileName, "r");
    if (!dictionary)
        return NULL;
}