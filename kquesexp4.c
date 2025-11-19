/* Create a data structure kQueues that represents ‘k’ queues. Implementation of kQueues should use only one array, i.e., k queues should use the same array for storing elements. The following functions must be supported by kQueues. a. enqueue(int x, int qn):  adds x to queue number ‘qn’ where qn is from 0 to k-1. b. dequeue(int qn): deletes an element from queue number ‘qn’ where qn is from 0 to k-1. c. displayq( int q ): displays all the elements of the q specified. d. displayAll( ):displays the contents of all the queues. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define K   5   // example number of queues

int arr[MAX];        // actual storage
int frontQ[K], rearQ[K]; // front and rear indices for each queue
int next[MAX];       // next index for linked lists and free list
int freeIndex;       // beginning of free list

/* initialize k queues */
void initKQueues(int k) {
    for (int i = 0; i < k; i++) { frontQ[i] = -1; rearQ[i] = -1; }
    for (int i = 0; i < MAX-1; i++) next[i] = i+1;
    next[MAX-1] = -1;
    freeIndex = 0;
}

/* check if array is full */
int isFull() { return freeIndex == -1; }

/* check if particular queue is empty */
int isEmpty(int qn) { return frontQ[qn] == -1; }

/* enqueue x into queue number qn */
void enqueue(int x, int qn) {
    if (isFull()) { printf("Overflow\n"); return; }
    int i = freeIndex;         // take free slot
    freeIndex = next[i];       // update free to next
    arr[i] = x;
    next[i] = -1;
    if (isEmpty(qn)) frontQ[qn] = rearQ[qn] = i;
    else { next[rearQ[qn]] = i; rearQ[qn] = i; }
}

/* dequeue from queue qn */
int dequeue(int qn) {
    if (isEmpty(qn)) { printf("Underflow\n"); return -1; }
    int i = frontQ[qn];
    frontQ[qn] = next[i];
    if (frontQ[qn] == -1) rearQ[qn] = -1;
    next[i] = freeIndex;
    freeIndex = i;
    return arr[i];
}

/* display specific queue */
void displayq(int qn) {
    int i = frontQ[qn];
    while (i != -1) { printf("%d ", arr[i]); i = next[i]; }
    printf("\n");
}

/* display all queues */
void displayAll(int k) {
    for (int q = 0; q < k; q++) {
        printf("Queue %d: ", q);
        displayq(q);
    }
}

int main() {
    initKQueues(K);
    enqueue(10, 0); enqueue(20, 1); enqueue(30, 2);
    enqueue(11, 0); enqueue(21, 1);
    displayAll(K);
    printf("Dequeue from 1: %d\n", dequeue(1));
    displayAll(K);
    return 0;
}
