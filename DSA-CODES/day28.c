#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // create circular linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // make it circular
    if (temp != NULL) {
        temp->next = head;
    }

    // traverse (avoid infinite loop)
    if (head != NULL) {
        struct Node* curr = head;
        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while (curr != head);
    }

    return 0;
}