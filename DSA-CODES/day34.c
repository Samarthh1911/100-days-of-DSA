#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = top;
    top = node;
}

int pop() {
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char token[20];
    
    while (scanf("%s", token) != EOF) {
        // Operand: push
        if (strcmp(token, "+") && strcmp(token, "-") &&
            strcmp(token, "*") && strcmp(token, "/")) {
            push(atoi(token));
        }
        // Operator: pop two, compute, push result
        else {
            int b = pop();
            int a = pop();
            int result;
            
            if      (token[0] == '+') result = a + b;
            else if (token[0] == '-') result = a - b;
            else if (token[0] == '*') result = a * b;
            else                      result = a / b;
            
            push(result);
        }
    }
    
    printf("%d\n", pop());
    return 0;
}