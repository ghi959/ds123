/* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. You should preserve the original relative order of the nodes in each of the two partitions. For example: ●    Input: 1 → 5 → 3 → 2 → 4 → 2  and x = 3 ●       Output: 1 → 2 → 2 → 3 → 5 → 4 */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->next = NULL; return n; }

/* append helper */
void append(struct Node **head, int x) {
    struct Node *n = newNode(x);
    if (!*head) { *head = n; return; }
    struct Node *p = *head;
    while (p->next) p = p->next;
    p->next = n;
}

/* partition preserving relative order using two lists */
struct Node* partitionList(struct Node *head, int x) {
    struct Node *beforeHead = NULL, *beforeTail = NULL;
    struct Node *afterHead = NULL, *afterTail = NULL;
    struct Node *curr = head;
    while (curr) {
        struct Node *next = curr->next;
        curr->next = NULL;
        if (curr->data < x) {
            if (!beforeHead) beforeHead = beforeTail = curr;
            else { beforeTail->next = curr; beforeTail = curr; }
        } else {
            if (!afterHead) afterHead = afterTail = curr;
            else { afterTail->next = curr; afterTail = curr; }
        }
        curr = next;
    }
    if (!beforeHead) return afterHead;
    beforeTail->next = afterHead;
    return beforeHead;
}

/* print */
void printList(struct Node *head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    append(&head, 1); append(&head, 5); append(&head, 3); append(&head, 2); append(&head, 4); append(&head, 2);
    printf("Before: "); printList(head);
    head = partitionList(head, 3);
    printf("After: "); printList(head);
    return 0;
}
