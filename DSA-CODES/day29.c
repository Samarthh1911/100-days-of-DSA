#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // create list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    if (n == 0 || k == 0) {
        temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // find length and last node
    int len = 1;
    temp = head;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if (k == 0) {
        temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // make circular
    temp->next = head;

    // move to (len - k)th node
    int steps = len - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    // print result
    temp = newHead;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}