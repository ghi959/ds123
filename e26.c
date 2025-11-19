/* Swap nodes of a linked list in pairs */
#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

struct Node* newNode(int x){
    struct Node *n=malloc(sizeof *n);
    n->data=x; n->next=NULL; return n;
}

void append(struct Node **h,int x){
    struct Node *n=newNode(x);
    if(!*h){*h=n;return;}
    struct Node *p=*h;
    while(p->next)p=p->next;
    p->next=n;
}

/* swap pairs */
struct Node* swapPairs(struct Node *head){
    if(!head || !head->next) return head;

    struct Node *newHead=head->next;
    struct Node *prev=NULL,*curr=head;

    while(curr && curr->next){
        struct Node *nextPair=curr->next->next;
        struct Node *second=curr->next;

        second->next=curr;
        curr->next=nextPair;
        if(prev) prev->next=second;

        prev=curr;
        curr=nextPair;
    }
    return newHead;
}

void print(struct Node *p){
    while(p){ printf("%d -> ",p->data); p=p->next; }
    printf("NULL\n");
}

int main(){
    struct Node *head=NULL;
    append(&head,1); append(&head,2); append(&head,3); append(&head,4);
    head=swapPairs(head);
    print(head);
    return 0;
}
