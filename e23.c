/* Add 2 non-negative numbers that have been given as a linked list */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };

struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof *n);
    n->data = x; n->next = NULL;
    return n;
}

void append(struct Node **head, int x) {
    struct Node *n = newNode(x);
    if (!*head) { *head = n; return; }
    struct Node *p = *head;
    while (p->next) p = p->next;
    p->next = n;
}

/* reverse LL helper for easy addition */
struct Node* reverse(struct Node *head) {
    struct Node *prev = NULL, *next;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/* add two linked-list numbers */
struct Node* add(struct Node *a, struct Node *b) {
    a = reverse(a);
    b = reverse(b);

    struct Node *res = NULL;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->data; a = a->next; }
        if (b) { sum += b->data; b = b->next; }
        carry = sum / 10;
        append(&res, sum % 10);
    }

    return reverse(res);
}

void print(struct Node *p) {
    while (p) { printf("%d -> ", p->data); p = p->next; }
    printf("NULL\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL;
    append(&p1,7); append(&p1,2); append(&p1,3); append(&p1,3);
    append(&p2,5); append(&p2,7); append(&p2,4);

    struct Node *sum = add(p1, p2);
    print(sum);
    return 0;
}
