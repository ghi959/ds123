/* Conversion of Infix expression to postfix expression using stack. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 200

char st[MAX];
int top = -1;

/* push character onto stack */
void push(char c) { if (top < MAX-1) st[++top] = c; }

/* pop character from stack */
char pop() { if (top >= 0) return st[top--]; return '\0'; }

/* peek top of stack */
char peek() { if (top >= 0) return st[top]; return '\0'; }

/* precedence of operators */
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

/* main conversion: read infix and write postfix into out */
void infixToPostfix(const char *in, char *out) {
    int j = 0;
    for (int i = 0; in[i]; i++) {
        char c = in[i];
        if (isspace(c)) continue;          // skip spaces
        if (isalnum(c)) out[j++] = c;     // operand -> output
        else if (c == '(') push(c);       // left paren -> push
        else if (c == ')') {              // pop until '('
            while (top != -1 && peek() != '(') out[j++] = pop();
            pop(); // remove '('
        } else {                          // operator
            while (top != -1 && prec(peek()) >= prec(c)) out[j++] = pop();
            push(c);
        }
    }
    while (top != -1) out[j++] = pop();  // empty stack
    out[j] = '\0';
}

int main() {
    char in[MAX], out[MAX];
    printf("Enter infix expression: ");
    if (!fgets(in, sizeof in, stdin)) return 0;
    in[strcspn(in, "\n")] = '\0';
    infixToPostfix(in, out);
    printf("Postfix: %s\n", out);
    return 0;
}
