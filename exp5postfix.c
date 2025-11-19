/* Evaluation of Postfix expression using Stack */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

int st[MAX];
int top = -1;

/* push integer */
void push(int v) { if (top < MAX-1) st[++top] = v; }

/* pop integer */
int pop() { if (top >= 0) return st[top--]; return 0; }

/* evaluate postfix expression; expects space-separated tokens for simplicity */
int evaluatePostfix(const char *expr) {
    int i = 0;
    while (expr[i]) {
        if (isspace(expr[i])) { i++; continue; }
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) { num = num*10 + (expr[i]-'0'); i++; }
            push(num);
        } else {
            int b = pop(); int a = pop();
            char op = expr[i++];
            if (op == '+') push(a + b);
            else if (op == '-') push(a - b);
            else if (op == '*') push(a * b);
            else if (op == '/') push(a / b);
        }
    }
    return pop();
}

int main() {
    char expr[MAX];
    printf("Enter postfix (tokens separated by spaces): ");
    if (!fgets(expr, sizeof expr, stdin)) return 0;
    expr[strcspn(expr, "\n")] = '\0';
    printf("Result: %d\n", evaluatePostfix(expr));
    return 0;
}
