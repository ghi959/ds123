/* PS: Infix to Prefix conversion using stack (simple method: reverse + swap + postfix) */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void reverseStr(char *s) {
    int i = 0, j = strlen(s)-1; 
    while (i < j) { char t = s[i]; s[i++] = s[j]; s[j--] = t; }
}

int isOperator(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*'||c == '/') return 2;
    if (c == '+'||c == '-') return 1;
    return 0;
}

void infixToPostfix(char *in, char *out) {
    char stack[MAX]; int top=-1; int j=0;
    for (int i=0; in[i]; i++) {
        char c = in[i];
        if (isspace(c)) continue;
        if (isalnum(c)) out[j++] = c;
        else if (c == '(') stack[++top]=c;
        else if (c == ')') {
            while (top!=-1 && stack[top] != '(') out[j++]=stack[top--];
            if (top!=-1) top--;
        } else {
            while (top!=-1 && prec(stack[top]) >= prec(c)) out[j++]=stack[top--];
            stack[++top]=c;
        }
    }
    while (top!=-1) out[j++] = stack[top--];
    out[j] = '\0';
}

void infixToPrefix(char *in, char *out) {
    char tmp[MAX], tmp2[MAX];
    strcpy(tmp, in);
    reverseStr(tmp);
    // swap '(' and ')'
    for (int i=0; tmp[i]; i++) if (tmp[i]=='(') tmp[i]=')'; else if (tmp[i]==')') tmp[i]='(';
    infixToPostfix(tmp, tmp2);
    reverseStr(tmp2);
    strcpy(out, tmp2);
}

int main() {
    char in[MAX], out[MAX];
    printf("Enter infix: ");
    fgets(in, MAX, stdin);
    in[strcspn(in,"\n")] = '\0';
    infixToPrefix(in, out);
    printf("Prefix: %s\n", out);
    return 0;
}
