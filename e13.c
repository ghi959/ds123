/* Given a sorted linked list, delete all duplicates such that each element appears only once. For example: ●    Given 1→1 → 2,                           return 1 → 2 ●       Given 1 → 1 → 2 → 3 → 3,        return 1 → 2 → 3 */
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };

struct Node* newNode(int x) { struct Node *n = malloc(sizeof *n); n->data = x; n->next = NULL; return n; }

/* insert at end helper */
void append(struct Node **head, int x) {
    struct Node *n = newNode(x);
    if (!*head) { *head = n; return; }
    struct Node *p = *head;
    while (p->next) p = p->next;
    p->next = n;
}

/* remove duplicates from sorted list */
void removeDuplicates(struct Node *head) {
    struct Node *curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            struct Node *tmp = curr->next;
            curr->next = tmp->next;
            free(tmp);
        } else curr = curr->next;
    }
}

/* print list */
void printList(struct Node *head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    append(&head, 1); append(&head, 1); append(&head, 2); append(&head, 3); append(&head, 3);
    printf("Before: "); printList(head);
    removeDuplicates(head);
    printf("After: "); printList(head);
    return 0;
}
