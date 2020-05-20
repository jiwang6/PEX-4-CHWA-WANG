#include "dFuncts.h"

int main()
{
    Node *root = NULL;

    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "issue");
    insert(&root, "is");
    insert(&root, "doolie");

    printf("\nFollowing is traversal of ternary search tree\n");
    traverseTree(root);


    printf("\nsearching for inputs (should be all Found):\n");

    searchTree(root, "cat") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "cats") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "issue") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "is") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "doolie") ? printf("Found\n") : printf("Not Found\n");

    printf("\nsearching for not inputs (should be all Not Found):\n");
    searchTree(root, "ca") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "catss") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "iss") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "do") ? printf("Found\n") : printf("Not Found\n");
    searchTree(root, "doolies") ? printf("Found\n") : printf("Not Found\n");



    return 0;
}