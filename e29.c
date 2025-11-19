/* On a Doubly Linked List perform the following operations 1. Create 2. Display 3. Insert an element 4. Delete an element */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* newNode(int x){
    struct Node *n=malloc(sizeof *n);
    n->data=x; n->prev=n->next=NULL; return n;
}

/* insert at end */
void insert(struct Node **h,int x){
    struct Node *n=newNode(x);
    if(!*h){*h=n;return;}
    struct Node *p=*h;
    while(p->next)p=p->next;
    p->next=n; n->prev=p;
}

/* delete first occurrence of x */
void delete(struct Node **h,int x){
    struct Node *p=*h;
    while(p){
        if(p->data==x){
            if(p->prev) p->prev->next=p->next;
            else *h=p->next;
            if(p->next) p->next->prev=p->prev;
            free(p);
            return;
        }
        p=p->next;
    }
}

/* display */
void display(struct Node *p){
    while(p){ printf("%d <-> ",p->data); p=p->next; }
    printf("NULL\n");
}

int main(){
    struct Node *head=NULL;
    insert(&head,1); insert(&head,2); insert(&head,3);
    display(head);

    insert(&head,4);
    display(head);

    delete(&head,2);
    display(head);

    return 0;
}
