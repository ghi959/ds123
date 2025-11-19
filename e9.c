/* Implement univariate Polynomial addition using linked lists. A univariate polynomial should be represented in the decreasing order of its exponent */
#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term *next;
};

/* create new term node */
struct Term* newTerm(int c, int e) {
    struct Term *t = malloc(sizeof *t);
    t->coeff = c; t->exp = e; t->next = NULL;
    return t;
}

/* append term at end (input polynomials already in decreasing exponent order) */
void appendTerm(struct Term **head, int c, int e) {
    struct Term *t = newTerm(c, e);
    if (!*head) { *head = t; return; }
    struct Term *p = *head;
    while (p->next) p = p->next;
    p->next = t;
}

/* add two polynomials */
struct Term* addPoly(struct Term *p1, struct Term *p2) {
    struct Term *res = NULL;
    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            appendTerm(&res, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next; p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            appendTerm(&res, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            appendTerm(&res, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1) { appendTerm(&res, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2) { appendTerm(&res, p2->coeff, p2->exp); p2 = p2->next; }
    return res;
}

/* print polynomial */
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
    appendTerm(&p1, 5, 2); appendTerm(&p1, 4, 1); appendTerm(&p1, 2, 0); // 5x^2 +4x +2
    appendTerm(&p2, 3, 3); appendTerm(&p2, 2, 2); appendTerm(&p2, 1, 0); // 3x^3 +2x^2 +1
    printf("P1: "); printPoly(p1);
    printf("P2: "); printPoly(p2);
    struct Term *sum = addPoly(p1, p2);
    printf("Sum: "); printPoly(sum);
    return 0;
}
