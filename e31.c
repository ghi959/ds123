/* Implement queue using singly linked list 1. enqueue 2. Dequeue 3. Display  4. Front 5. Rear */
#include <stdio.h>
#include <stdlib.h>

struct Node{ int data; struct Node *next; };

struct Node *front=NULL,*rear=NULL;

/* enqueue */
void enqueue(int x){
    struct Node *n=malloc(sizeof *n);
    n->data=x; n->next=NULL;
    if(!rear){ front=rear=n; return; }
    rear->next=n;
    rear=n;
}

/* dequeue */
int dequeue(){
    if(!front){ printf("Underflow\n"); return -1; }
    struct Node *t=front;
    int v=t->data;
    front=front->next;
    if(!front) rear=NULL;
    free(t);
    return v;
}

/* display */
void display(){
    struct Node *p=front;
    while(p){ printf("%d -> ",p->data); p=p->next; }
    printf("NULL\n");
}

int main(){
    enqueue(1); enqueue(2); enqueue(3);
    display();
    printf("Deq: %d\n", dequeue());
    display();
    printf("Front: %d Rear: %d\n", front->data, rear->data);
    return 0;
}
