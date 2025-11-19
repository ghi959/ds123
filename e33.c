/* Create a binary tree and traverse the tree level by level. */
#include <stdio.h>
#include <stdlib.h>

/* node */
struct Node { int data; struct Node *left, *right; };

/* create node */
struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof *n);
    n->data = x; n->left = n->right = NULL; return n;
}

/* simple queue for level order (store pointers) */
#define QMAX 100
struct Node* queue[QMAX];
int front = 0, rear = 0;

void qpush(struct Node *p) { if (rear < QMAX) queue[rear++] = p; }
struct Node* qpop() { if (front < rear) return queue[front++]; return NULL; }
int qisEmpty() { return front >= rear; }

void levelOrder(struct Node *root) {
    if (!root) return;
    front = rear = 0;
    qpush(root);
    while (!qisEmpty()) {
        struct Node *cur = qpop();
        printf("%d ", cur->data);
        if (cur->left) qpush(cur->left);
        if (cur->right) qpush(cur->right);
    }
}

int main() {
    /* sample tree */
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level order: ");
    levelOrder(root);
    printf("\n");
    return 0;
}
