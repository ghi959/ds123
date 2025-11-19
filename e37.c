/* Create a binary tree and perform nonrecursive inorder traversal of it. */
#include <stdio.h>
#include <stdlib.h>

/* node */
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->left = n->right = NULL; return n; }

/* stack of node pointers */
#define SMAX 100
struct Node* stack[SMAX];
int top = -1;
void push(struct Node *p) { if (top < SMAX-1) stack[++top] = p; }
struct Node* pop() { if (top >= 0) return stack[top--]; return NULL; }
int sisEmpty() { return top == -1; }

/* non-recursive inorder */
void inorderNonRecursive(struct Node *root) {
    struct Node *curr = root;
    while (curr || !sisEmpty()) {
        while (curr) { push(curr); curr = curr->left; }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder (non-recursive): ");
    inorderNonRecursive(root);
    printf("\n");
    return 0;
}
