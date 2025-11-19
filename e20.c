/* Write a program to implement a Hash Table using linear probing as the collision resolution strategy. The table should support the following operations: a. Insert b. Search */
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

/* initialize */
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

/* insert using linear probing */
void insert(int key) {
    int index = key % SIZE;
    int i = index;

    while (hashTable[i] != -1) {
        i = (i + 1) % SIZE;
        if (i == index) { printf("Table full\n"); return; }
    }
    hashTable[i] = key;
}

/* search using linear probing */
int search(int key) {
    int index = key % SIZE;
    int i = index;

    while (hashTable[i] != -1) {
        if (hashTable[i] == key) return i;
        i = (i + 1) % SIZE;
        if (i == index) break;
    }
    return -1;
}

int main() {
    init();
    insert(15); insert(25); insert(35);

    int s = search(25);
    if (s != -1) printf("Found at %d\n", s);
    else printf("Not found\n");
    return 0;
}
