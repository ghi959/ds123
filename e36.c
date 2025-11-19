/* Create Binary tree and perform the following operations

1. Count terminal nodes 2. Count non terminal nodes 3.count total nodes */
#include <stdio.h>
#include <stdlib.h>

/* node */
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->left = n->right = NULL; return n; }

/* count total nodes */
int countTotal(struct Node *root) {
    if (!root) return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

/* count terminal (leaf) nodes */
int countTerminal(struct Node *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countTerminal(root->left) + countTerminal(root->right);
}

/* count non-terminal (internal) nodes */
int countNonTerminal(struct Node *root) {
    int total = countTotal(root);
    int leaf = countTerminal(root);
    return total - leaf;
}

int main() {
    /* sample tree */
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Total nodes: %d\n", countTotal(root));
    printf("Terminal (leaf) nodes: %d\n", countTerminal(root));
    printf("Non-terminal (internal) nodes: %d\n", countNonTerminal(root));
    return 0;
}
