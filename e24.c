/* Implement the Max Heap tree and sort the elements. The following operations should be supported: a. heapify b. extractMax (Deleting the max element) c. heapsort */
#include <stdio.h>

#define MAX 50

int heap[MAX];
int size = 0;

void swap(int *a, int *b) { int t=*a; *a=*b; *b=t; }

/* heapify down for max heap */
void heapify(int i) {
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

/* insert */
void insert(int x) {
    heap[size] = x;
    int i = size;
    size++;

    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

/* extract max */
int extractMax() {
    if (size == 0) return -1;
    int root = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return root;
}

/* heapsort */
void heapSort() {
    int temp[MAX], idx = 0;
    int original = size;

    for (int i = 0; i < original; i++)
        temp[idx++] = extractMax();

    printf("Sorted descending: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", temp[i]);
    printf("\n");
}

int main() {
    insert(10); insert(4); insert(15); insert(2);
    heapSort();
    return 0;
}
