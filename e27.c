/* Implement recursive functions on Singly Linked List a. Create b. Display c. Length  d. Reverse */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };

struct Node* create(int x){
    struct Node *n=malloc(sizeof *n);
    n->data=x; n->next=NULL; return n;
}

/* recursive display */
void display(struct Node *h){
    if(!h) return;
    printf("%d ",h->data);
    display(h->next);
}

/* recursive length */
int length(struct Node *h){
    if(!h) return 0;
    return 1 + length(h->next);
}

/* recursive reverse */
struct Node* reverse(struct Node *h){
    if(!h || !h->next) return h;
    struct Node *rest=reverse(h->next);
    h->next->next=h;
    h->next=NULL;
    return rest;
}

int main(){
    struct Node *head=create(1);
    head->next=create(2);
    head->next->next=create(3);

    printf("List: "); display(head); printf("\n");
    printf("Len: %d\n", length(head));

    head=reverse(head);
    printf("Reversed: "); display(head);
    return 0;
}
