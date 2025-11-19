/* Rotate a Linked List by ‘k’ places. */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };

struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof *n);
    n->data = x; n->next = NULL; return n;
}

void append(struct Node **head, int x) {
    struct Node *n = newNode(x);
    if (!*head) { *head = n; return; }
    struct Node *p=*head;
    while (p->next) p=p->next;
    p->next=n;
}

/* rotate LL by k */
struct Node* rotate(struct Node *head, int k) {
    if (!head || k==0) return head;

    struct Node *p=head;
    int len=1;
    while (p->next) { p=p->next; len++; }
    p->next=head;

    k = k % len;

    int steps = len - k;
    for (int i=0; i<steps; i++) p=p->next;

    head = p->next;
    p->next=NULL;
    return head;
}

void print(struct Node *h) {
    while (h){ printf("%d -> ",h->data); h=h->next; }
    printf("NULL\n");
}

int main(){
    struct Node *head=NULL;
    append(&head,1); append(&head,2); append(&head,3);
    append(&head,4); append(&head,5);

    head = rotate(head,2);
    print(head);
    return 0;
}
