#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int var;
    struct node *left;
    struct node *right;
} node;

struct node * createNode();

int main () {
    struct node *root;
    root = createNode();
    return 0;
}

struct node * createNode() {
    //! showMemory(start=65520)
    int var;
    int terminate = -12345;
    struct node *newNode = (struct node *)malloc (sizeof(struct node));
    printf("Enter a variable to store (enter \"-12345\" for an empty node):\n");
    scanf("%d", &var);
    if (var == terminate) {
        return 0;
    }
    newNode-> var = var;
    printf("Creating left child for the variable %d...\n", newNode->var);
    newNode->left = createNode();
    printf("Creating right child for the variable %d...\n", newNode->var);
    newNode->right = createNode();
    return newNode;
}
