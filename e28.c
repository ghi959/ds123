/* Create  2 singly linked lists in Ascending order and a. merge b. Check if they are equal or not.  c. make a copy of the linked list. */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };

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

/* merge two ascending lists */
struct Node* merge(struct Node *a, struct Node *b){
    if(!a) return b;
    if(!b) return a;
    if(a->data < b->data){
        a->next=merge(a->next,b);
        return a;
    } else {
        b->next=merge(a,b->next);
        return b;
    }
}

/* check equality */
int isEqual(struct Node *a, struct Node *b){
    while(a && b){
        if(a->data!=b->data) return 0;
        a=a->next; b=b->next;
    }
    return a==NULL && b==NULL;
}

/* copy list */
struct Node* copy(struct Node *h){
    if(!h) return NULL;
    struct Node *newH=newNode(h->data);
    struct Node *p=newH;
    h=h->next;
    while(h){
        p->next=newNode(h->data);
        p=p->next;
        h=h->next;
    }
    return newH;
}

void print(struct Node *p){
    while(p){ printf("%d -> ",p->data); p=p->next; }
    printf("NULL\n");
}

int main(){
    struct Node *a=NULL,*b=NULL;
    append(&a,1); append(&a,3); append(&a,5);
    append(&b,2); append(&b,4); append(&b,6);

    printf("Merged: ");
    struct Node *m=merge(a,b);
    print(m);

    struct Node *c=copy(m);
    printf("Copy: "); print(c);

    printf("Equal? %d\n", isEqual(m,c));
    return 0;
}
