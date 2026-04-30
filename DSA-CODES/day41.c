#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear  = NULL;

void enqueue(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    if (rear == NULL) { front = rear = node; }
    else { rear->next = node; rear = node; }
}

void dequeue() {
    if (front == NULL) { printf("-1\n"); return; }
    struct Node* temp = front;
    printf("%d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            int val; scanf("%d", &val);
            enqueue(val);
        } else if (strcmp(op, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}