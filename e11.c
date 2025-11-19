/* Implement the following operations on doubly linked lists: a. Insert (after position)   b. sort the list    c. display */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

/* create node */
struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof *n);
    n->data = x; n->prev = n->next = NULL; return n;
}

/* insert at end (helper) */
void insertEnd(struct Node **head, int x) {
    struct Node *n = newNode(x);
    if (!*head) { *head = n; return; }
    struct Node *p = *head;
    while (p->next) p = p->next;
    p->next = n; n->prev = p;
}

/* insert after given position (0-based). if pos = 0 insert after head. */
void insertAfterPos(struct Node **head, int pos, int x) {
    if (!*head && pos > 0) return;
    struct Node *p = *head;
    for (int i = 0; p && i < pos; i++) p = p->next;
    struct Node *n = newNode(x);
    if (!p) { *head = n; return; }
    n->next = p->next;
    n->prev = p;
    if (p->next) p->next->prev = n;
    p->next = n;
}

/* simple bubble sort by swapping data (beginner-friendly) */
void sortList(struct Node *head) {
    if (!head) return;
    int swapped;
    do {
        swapped = 0;
        struct Node *p = head;
        while (p->next) {
            if (p->data > p->next->data) {
                int t = p->data; p->data = p->next->data; p->next->data = t;
                swapped = 1;
            }
            p = p->next;
        }
    } while (swapped);
}

/* display list left to right */
void display(struct Node *head) {
    while (head) { printf("%d <-> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    insertEnd(&head, 3); insertEnd(&head, 1); insertEnd(&head, 4);
    printf("Before: "); display(head);
    insertAfterPos(&head, 1, 2); // insert 2 after position 1
    printf("After insert: "); display(head);
    sortList(head);
    printf("After sort: "); display(head);
    return 0;
}
