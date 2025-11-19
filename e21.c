/* Write a program to implement a Hash Table using quadratic probing as the collision resolution strategy. The table should support the following operations: a. Insert b. Search */
#include <stdio.h>

#define SIZE 10

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

/* quadratic probing insert */
void insert(int key) {
    int index = key % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i*i) % SIZE;
        if (table[pos] == -1) {
            table[pos] = key;
            return;
        }
    }
    printf("Table full\n");
}

/* quadratic probing search */
int search(int key) {
    int index = key % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i*i) % SIZE;
        if (table[pos] == key) return pos;
        if (table[pos] == -1) return -1;
    }
    return -1;
}

int main() {
    init();
    insert(10); insert(20); insert(30);

    int s = search(20);
    if (s != -1) printf("Found at %d\n", s);
    else printf("Not found\n");
    return 0;
}
