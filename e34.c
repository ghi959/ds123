/* Create a BST and print the output in Descending Order. */
#include <stdio.h>
#include <stdlib.h>

/* BST node */
struct Node { int data; struct Node *left, *right; };

struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->left = n->right = NULL; return n; }

/* insert into BST */
struct Node* insert(struct Node *root, int x) {
    if (!root) return newNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

/* print in descending order: right -> root -> left */
void printDescending(struct Node *root) {
    if (!root) return;
    printDescending(root->right);
    printf("%d ", root->data);
    printDescending(root->left);
}

int main() {
    struct Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);

    printf("BST in descending order: ");
    printDescending(root);
    printf("\n");
    return 0;
}
