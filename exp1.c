/* PS: Infix to Postfix conversion using stack */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { if (top < MAX-1) stack[++top] = c; }
char pop() { if (top >= 0) return stack[top--]; return '\0'; }
char peek() { if (top >= 0) return stack[top]; return '\0'; }

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char *in, char *out) {
    int j = 0;
    for (int i = 0; in[i]; i++) {
        char c = in[i];
        if (isspace(c)) continue;
        if (isalnum(c)) out[j++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top != -1 && peek() != '(') out[j++] = pop();
            pop(); // remove '('
        } else { // operator
            while (top != -1 && prec(peek()) >= prec(c)) out[j++] = pop();
            push(c);
        }
    }
    while (top != -1) out[j++] = pop();
    out[j] = '\0';
}

int main() {
    char in[MAX], out[MAX];
    printf("Enter infix expression: ");
    fgets(in, MAX, stdin);
    in[strcspn(in, "\n")] = '\0';
    infixToPostfix(in, out);
    printf("Postfix: %s\n", out);
    return 0;
}
