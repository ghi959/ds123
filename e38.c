/* Given inorder and preorder traversal of a tree , construct a tree and
perform postorder traversal ( Recursive ) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* node */
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->left = n->right = NULL; return n; }

/* find index of value in inorder array */
int findIndex(int in[], int start, int end, int val) {
    for (int i = start; i <= end; i++) if (in[i] == val) return i;
    return -1;
}

/* utility to build tree from preorder and inorder */
struct Node* build(int pre[], int in[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd) return NULL;
    int rootVal = pre[(*preIndex)++];
    struct Node *root = newNode(rootVal);
    if (inStart == inEnd) return root;

    int inIndex = findIndex(in, inStart, inEnd, rootVal);
    root->left = build(pre, in, inStart, inIndex - 1, preIndex);
    root->right = build(pre, in, inIndex + 1, inEnd, preIndex);
    return root;
}

/* postorder traversal */
void postorder(struct Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    /* example: inorder and preorder for tree */
    int inorderArr[] = {4, 2, 5, 1, 3};
    int preorderArr[] = {1, 2, 4, 5, 3};
    int n = sizeof(inorderArr)/sizeof(inorderArr[0]);
    int preIndex = 0;
    struct Node *root = build(preorderArr, inorderArr, 0, n-1, &preIndex);

    printf("Postorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
