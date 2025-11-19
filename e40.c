/* Create a binary tree and perform nonrecursive postorder traversal of it. */
#include <stdio.h>
#include <stdlib.h>

/* node */
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->left = n->right = NULL; return n; }

/* two-stack method for postorder (simple for beginners) */
#define SMAX 100
struct Node* stack1[SMAX];
struct Node* stack2[SMAX];
int top1=-1, top2=-1;
void push1(struct Node *p){ if(top1<SMAX-1) stack1[++top1]=p; }
struct Node* pop1(){ if(top1>=0) return stack1[top1--]; return NULL; }
int empty1(){ return top1==-1; }

void push2(struct Node *p){ if(top2<SMAX-1) stack2[++top2]=p; }
struct Node* pop2(){ if(top2>=0) return stack2[top2--]; return NULL; }
int empty2(){ return top2==-1; }

void postorderNonRecursive(struct Node *root) {
    if (!root) return;
    top1 = top2 = -1;
    push1(root);
    while (!empty1()) {
        struct Node *node = pop1();
        push2(node);
        if (node->left) push1(node->left);
        if (node->right) push1(node->right);
    }
    while (!empty2()) {
        struct Node *n = pop2();
        printf("%d ", n->data);
    }
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Postorder (non-recursive): ");
    postorderNonRecursive(root);
    printf("\n");
    return 0;
}
