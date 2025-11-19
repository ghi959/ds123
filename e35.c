/* Create two hard coded trees with roots, root1 and root2 and
1. To check if they are equal or not.
2. To make mirror image by swapping every node with its sibling. */
#include <stdio.h>
#include <stdlib.h>

/* node */
struct Node { int data; struct Node *left, *right; };
struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->left = n->right = NULL; return n; }

/* check structural + data equality */
int isEqual(struct Node *a, struct Node *b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    if (a->data != b->data) return 0;
    return isEqual(a->left, b->left) && isEqual(a->right, b->right);
}

/* make mirror image by swapping left and right recursively */
void makeMirror(struct Node *root) {
    if (!root) return;
    struct Node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    makeMirror(root->left);
    makeMirror(root->right);
}

/* inorder print for demonstration */
void inorder(struct Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    /* hard coded root1 */
    struct Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    /* hard coded root2 */
    struct Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    printf("Are equal? %s\n", isEqual(root1, root2) ? "Yes" : "No");

    printf("Root1 inorder before mirror: ");
    inorder(root1);
    printf("\n");

    makeMirror(root1);

    printf("Root1 inorder after mirror: ");
    inorder(root1);
    printf("\n");

    return 0;
}
