/* Given a singly linked list, determine if it's a palindrome. Return 1 or 0 denoting if it's a palindrome or not, respectively. For example a. List 1 → 2 → 1 is a palindrome. b. List 1 → 2 → 3 is not a palindrome. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* insert at front for easy construction */
void push(struct Node **head, int x) {
    struct Node *n = malloc(sizeof *n);
    n->data = x; n->next = *head; *head = n;
}

/* simple method: copy list into array then compare */
int isPalindrome(struct Node *head) {
    int arr[1000], n = 0;
    struct Node *p = head;
    while (p) { arr[n++] = p->data; p = p->next; }
    p = head;
    for (int i = n-1; i >= 0; i--) {
        if (p->data != arr[i]) return 0;
        p = p->next;
    }
    return 1;
}

/* print list */
void printList(struct Node *head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    push(&head, 1); push(&head, 2); push(&head, 1); // creates 1->2->1
    printList(head);
    printf("Is palindrome? %d\n", isPalindrome(head));
    return 0;
}
