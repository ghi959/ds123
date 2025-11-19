/* Evaluation of Prefix expression using Stack */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

int st[MAX];
int top = -1;

/* push */
void push(int v) { if (top < MAX-1) st[++top] = v; }

/* pop */
int pop() { if (top >= 0) return st[top--]; return 0; }

/* evaluate prefix expression; tokens separated by spaces */
int evaluatePrefix(const char *expr) {
    int n = strlen(expr);
    for (int i = n-1; i >= 0; i--) {
        if (isspace(expr[i])) continue;
        if (isdigit(expr[i])) {
            int j = i;
            while (j >= 0 && isdigit(expr[j])) j--;
            int num = 0;
            for (int k = j+1; k <= i; k++) num = num*10 + (expr[k]-'0');
            push(num);
            i = j+1 - 1;
        } else {
            int a = pop(); int b = pop();
            char op = expr[i];
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
    printf("Enter prefix (tokens separated by spaces): ");
    if (!fgets(expr, sizeof expr, stdin)) return 0;
    expr[strcspn(expr, "\n")] = '\0';
    printf("Result: %d\n", evaluatePrefix(expr));
    return 0;
}
