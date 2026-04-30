#include <stdio.h>
#include <string.h>

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    char stack[100];
    int top = -1, j = 0;
    
    scanf("%s", infix);
    int n = strlen(infix);
    
    for (int i = 0; i < n; i++) {
        char c = infix[i];
        
        // Operand: directly to output
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            postfix[j++] = c;
        }
        // Open bracket: push
        else if (c == '(') {
            stack[++top] = c;
        }
        // Close bracket: pop until '('
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--; // discard '('
        }
        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        }
    }
    
    // Pop remaining operators
    while (top != -1)
        postfix[j++] = stack[top--];
    
    postfix[j] = '\0';
    printf("%s\n", postfix);
    
    return 0;
}