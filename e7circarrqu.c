/* Write a program to implement Queue using a circular array. The following operations need to be supported: a. enqueue b. dequeue c. isEmpty d. isFull e. front f. rear */
#include <stdio.h>
#define MAX 5

int arr[MAX];
int front = -1, rear = -1;

/* check empty */
int isEmpty() { return front == -1; }

/* check full */
int isFull() { return (front == (rear + 1) % MAX); }

/* enqueue element */
void enqueue(int x) {
    if (isFull()) { printf("Queue is full\n"); return; }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    arr[rear] = x;
}

/* dequeue element */
int dequeue() {
    if (isEmpty()) { printf("Queue is empty\n"); return -1; }
    int val = arr[front];
    if (front == rear) front = rear = -1; // now empty
    else front = (front + 1) % MAX;
    return val;
}

/* get front element */
int getFront() { if (isEmpty()) { printf("Empty\n"); return -1; } return arr[front]; }

/* get rear element */
int getRear() { if (isEmpty()) { printf("Empty\n"); return -1; } return arr[rear]; }

/* display queue contents */
void display() {
    if (isEmpty()) { printf("Queue empty\n"); return; }
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30); enqueue(40); enqueue(50);
    display();
    printf("Dequeued: %d\n", dequeue());
    enqueue(60);
    display();
    printf("Front: %d Rear: %d\n", getFront(), getRear());
    return 0;
}
