/* Implement univariate Polynomial Multiplication using linked lists. A univariate polynomial should be represented in the decreasing order of its exponent . */
#include <stdio.h>
#include <stdlib.h>

struct Term { int coeff; int exp; struct Term *next; };

/* create term */
struct Term* newTerm(int c, int e) {
    struct Term *t = malloc(sizeof *t);
    t->coeff = c; t->exp = e; t->next = NULL;
    return t;
}

/* append term at end */
void append(struct Term **head, int c, int e) {
    struct Term *t = newTerm(c, e);
    if (!*head) { *head = t; return; }
    struct Term *p = *head;
    while (p->next) p = p->next;
    p->next = t;
}

/* add result coefficient into appropriate exponent slot (keeps list sorted desc) */
void addToResult(struct Term **res, int c, int e) {
    struct Term *p = *res, *prev = NULL;
    while (p && p->exp > e) { prev = p; p = p->next; }
    if (p && p->exp == e) p->coeff += c;
    else {
        struct Term *t = newTerm(c, e);
        if (!prev) { t->next = *res; *res = t; }
        else { t->next = prev->next; prev->next = t; }
    }
}

/* naive multiply each term of p1 with each term of p2 */
struct Term* multiply(struct Term *p1, struct Term *p2) {
    struct Term *res = NULL;
    for (struct Term *a = p1; a; a = a->next)
        for (struct Term *b = p2; b; b = b->next)
            addToResult(&res, a->coeff * b->coeff, a->exp + b->exp);
    return res;
}

/* print poly */
void printPoly(struct Term *p) {
    while (p) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct Term *p1 = NULL, *p2 = NULL;
    append(&p1, 3, 2); append(&p1, 2, 1); // 3x^2 + 2x
    append(&p2, 1, 1); append(&p2, 4, 0); // x + 4
    printf("P1: "); printPoly(p1);
    printf("P2: "); printPoly(p2);
    struct Term *prod = multiply(p1, p2);
    printf("Product: "); printPoly(prod);
    return 0;
}
