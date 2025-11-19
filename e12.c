/* Implement the following operations on doubly linked lists: a. Insert (end) b. concatenate two lists c. display */
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

/* insert at end */
void insertEnd(struct Node **head, int x) {
    struct Node *n = newNode(x);
    if (!*head) { *head = n; return; }
    struct Node *p = *head;
    while (p->next) p = p->next;
    p->next = n; n->prev = p;
}

/* concatenate list2 at end of list1 */
void concatenate(struct Node **list1, struct Node *list2) {
    if (!*list1) { *list1 = list2; return; }
    struct Node *p = *list1;
    while (p->next) p = p->next;
    p->next = list2;
    if (list2) list2->prev = p;
}

/* display */
void display(struct Node *head) {
    while (head) { printf("%d <-> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node *a = NULL, *b = NULL;
    insertEnd(&a, 1); insertEnd(&a, 2); insertEnd(&a, 3);
    insertEnd(&b, 4); insertEnd(&b, 5);
    printf("List A: "); display(a);
    printf("List B: "); display(b);
    concatenate(&a, b);
    printf("After concat A: "); display(a);
    return 0;
}
