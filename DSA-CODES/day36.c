#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear  = NULL;

void enqueue(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = front;   // circular: new rear points to front
    
    if (rear == NULL) {
        front = rear = node;
        node->next = node; // points to itself
    } else {
        rear->next = node; // old rear → new node
        rear = node;       // update rear
        rear->next = front; // new rear → front (maintain circle)
    }
}

void dequeue() {
    if (front == NULL) return;
    
    if (front == rear) {
        // single element
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front; // maintain circle
        free(temp);
    }
}

void display() {
    if (front == NULL) return;
    
    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        dequeue();

    display();
    return 0;
}