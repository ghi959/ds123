/* Write a program to maintain multiple stacks in a single array. */
#include <stdio.h>
#define MAX 100

/* Simple beginner version: two stacks share one array */
int arr[MAX];
int top1 = -1;       // top for stack1 grows from left
int top2 = MAX;      // top for stack2 grows from right

/* push into first stack */
void push1(int x) {
    if (top1 + 1 < top2) arr[++top1] = x;
    else printf("Overflow: stack1\n");
}

/* push into second stack */
void push2(int x) {
    if (top2 - 1 > top1) arr[--top2] = x;
    else printf("Overflow: stack2\n");
}

/* pop from first stack */
int pop1() {
    if (top1 >= 0) return arr[top1--];
    printf("Underflow: stack1\n"); return -1;
}

/* pop from second stack */
int pop2() {
    if (top2 < MAX) return arr[top2++];
    printf("Underflow: stack2\n"); return -1;
}

int main() {
    /* very small demo */
    push1(10); push1(20); push2(30); push2(40);
    printf("pop1: %d\n", pop1());
    printf("pop2: %d\n", pop2());
    return 0;
}
