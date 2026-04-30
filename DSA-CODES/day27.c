#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

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
    return head;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* l1 = createList(n);

    scanf("%d", &m);
    struct Node* l2 = createList(m);

    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // align both lists
    while (len1 > len2) {
        l1 = l1->next;
        len1--;
    }
    while (len2 > len1) {
        l2 = l2->next;
        len2--;
    }

    // find first common value
    while (l1 && l2) {
        if (l1->data == l2->data) {
            printf("%d", l1->data);
            return 0;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    printf("No Intersection");
    return 0;
}