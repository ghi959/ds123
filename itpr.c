/* Conversion of Infix expression to prefix expression using stack. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

/* reverse string in place */
void reverseStr(char *s) {
    int i = 0, j = strlen(s)-1;
    while (i < j) { char t = s[i]; s[i++] = s[j]; s[j--] = t; }
}

/* check operator */
int isOp(char c) { return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }

/* precedence */
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

/* simple postfix converter used in algorithm */
void infixToPostfix(const char *in, char *out) {
    char st[MAX]; int top=-1; int j=0;
    for (int i=0; in[i]; i++) {
        char c = in[i];
        if (isspace(c)) continue;
        if (isalnum(c)) out[j++] = c;
        else if (c == '(') st[++top] = c;
        else if (c == ')') {
            while (top != -1 && st[top] != '(') out[j++] = st[top--];
            if (top != -1) top--; // pop '('
        } else {
            while (top != -1 && prec(st[top]) >= prec(c)) out[j++] = st[top--];
            st[++top] = c;
        }
    }
    while (top != -1) out[j++] = st[top--];
    out[j] = '\0';
}

/* convert infix -> prefix by reversing trick */
void infixToPrefix(const char *in, char *out) {
    char tmp[MAX], tmp2[MAX];
    strncpy(tmp, in, MAX); tmp[MAX-1] = '\0';
    reverseStr(tmp);
    for (int i = 0; tmp[i]; i++) { if (tmp[i] == '(') tmp[i] = ')'; else if (tmp[i] == ')') tmp[i] = '('; }
    infixToPostfix(tmp, tmp2);
    reverseStr(tmp2);
    strncpy(out, tmp2, MAX); out[MAX-1] = '\0';
}

int main() {
    char in[MAX], out[MAX];
    printf("Enter infix expression: ");
    if (!fgets(in, sizeof in, stdin)) return 0;
    in[strcspn(in, "\n")] = '\0';
    infixToPrefix(in, out);
    printf("Prefix: %s\n", out);
    return 0;
}
