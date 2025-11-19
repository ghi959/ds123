/* Create a binary tree and perform nonrecursive preorder traversal of it. */
#include <stdio.h>
#include <stdlib.h>

/* node */
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->left = n->right = NULL; return n; }

/* stack */
#define SMAX 100
struct Node* stack[SMAX];
int top = -1;
void push(struct Node *p) { if (top < SMAX-1) stack[++top] = p; }
struct Node* pop() { if (top >= 0) return stack[top--]; return NULL; }
int sisEmpty() { return top == -1; }

/* non-recursive preorder: root, left, right */
void preorderNonRecursive(struct Node *root) {
    if (!root) return;
    top = -1;
    push(root);
    while (!sisEmpty()) {
        struct Node *cur = pop();
        printf("%d ", cur->data);
        if (cur->right) push(cur->right); // push right first
        if (cur->left) push(cur->left);
    }
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder (non-recursive): ");
    preorderNonRecursive(root);
    printf("\n");
    return 0;
}
