/* Implement a Min Heap tree and sort the elements. The following operations should be supported: a. heapify b. extractMin (Deleting the min element) c. heapsort */
#include <stdio.h>

#define MAX 50

int heap[MAX];
int size = 0;

/* swap helper */
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

/* heapify down */
void heapify(int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

/* insert into heap */
void insert(int x) {
    heap[size] = x;
    int i = size;
    size++;

    /* heapify up */
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

/* extract minimum element */
int extractMin() {
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return root;
}

/* heapsort: repeatedly extract min */
void heapSort() {
    int temp[MAX], idx = 0;
    int original = size;

    for (int i = 0; i < original; i++)
        temp[idx++] = extractMin();

    printf("Sorted: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", temp[i]);
    printf("\n");
}

int main() {
    insert(5); insert(3); insert(8); insert(1);
    heapSort();
    return 0;
}
