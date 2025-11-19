/* Write a program to construct a binary search tree and traverse it with all methods that use recursion. */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

/* create node */
struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof *n);
    n->data = x; n->left = n->right = NULL; return n;
}

/* insert into BST */
struct Node* insert(struct Node *root, int x) {
    if (!root) return newNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

/* recursive traversals */
void inorder(struct Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* height of tree (recursive) */
int height(struct Node *root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int main() {
    struct Node *root = NULL;
    int vals[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    printf("Height: %d\n", height(root));
    return 0;
}
