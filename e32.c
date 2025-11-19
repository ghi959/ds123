/* Create a binary tree ( Recursive ) and perform following operations.
1. InOrder traversal 2. Height of the tree */
#include <stdio.h>
#include <stdlib.h>

/* basic binary tree node */
struct Node {
    int data;
    struct Node *left, *right;
};

/* create new node */
struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof *n);
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

/* inorder traversal (recursive) */
void inorder(struct Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* height of tree (recursive). height of empty tree = 0 */
int height(struct Node *root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int main() {
    /* create a sample tree:
            1
           / \
          2   3
         / \
        4   5
    */
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder: ");
    inorder(root);
    printf("\nHeight: %d\n", height(root));
    return 0;
}
