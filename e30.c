/* Implement stack using singly linked list 1. Push 2. Pop 3. Display topmost element 4. Display complete stack */
#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };
struct Node *top=NULL;

/* push */
void push(int x){
    struct Node *n=malloc(sizeof *n);
    n->data=x; n->next=top;
    top=n;
}

/* pop */
int pop(){
    if(!top){ printf("Underflow\n"); return -1; }
    struct Node *t=top;
    int v=t->data;
    top=top->next;
    free(t);
    return v;
}

/* peek */
int peek(){
    if(!top) return -1;
    return top->data;
}

/* display */
void display(){
    struct Node *p=top;
    while(p){ printf("%d -> ",p->data); p=p->next; }
    printf("NULL\n");
}

int main(){
    push(10); push(20); push(30);
    display();
    printf("Pop: %d\n", pop());
    printf("Top: %d\n", peek());
    display();
    return 0;
}
