#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear  = NULL;
int sz = 0;

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->prev = node->next = NULL;
    return node;
}

// ── Core Operations ──────────────────────────────────────────

void push_front(int val) {
    struct Node* node = newNode(val);
    if (front == NULL) { front = rear = node; }
    else { node->next = front; front->prev = node; front = node; }
    sz++;
}

void push_back(int val) {
    struct Node* node = newNode(val);
    if (rear == NULL) { front = rear = node; }
    else { rear->next = node; node->prev = rear; rear = node; }
    sz++;
}

void pop_front() {
    if (!front) { printf("Deque is empty\n"); return; }
    struct Node* temp = front;
    front = front->next;
    if (front) front->prev = NULL;
    else rear = NULL;
    printf("Popped from front: %d\n", temp->data);
    free(temp); sz--;
}

void pop_back() {
    if (!rear) { printf("Deque is empty\n"); return; }
    struct Node* temp = rear;
    rear = rear->prev;
    if (rear) rear->next = NULL;
    else front = NULL;
    printf("Popped from rear: %d\n", temp->data);
    free(temp); sz--;
}

void get_front() {
    if (!front) printf("Deque is empty\n");
    else        printf("Front: %d\n", front->data);
}

void get_back() {
    if (!rear) printf("Deque is empty\n");
    else       printf("Back: %d\n", rear->data);
}

void empty()  { printf(front == NULL ? "Deque is empty\n" : "Deque is not empty\n"); }
void size()   { printf("Size: %d\n", sz); }

// ── Additional Operations ─────────────────────────────────────

void display() {
    struct Node* t = front;
    printf("Deque: ");
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

void clear() {
    while (front) {
        struct Node* t = front;
        front = front->next;
        free(t);
    }
    rear = NULL; sz = 0;
    printf("Deque cleared\n");
}

void reverse() {
    struct Node* cur = front;
    struct Node* tmp = NULL;
    while (cur) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;       // move forward (was next)
    }
    if (tmp) front = tmp->prev;
    printf("Deque reversed\n");
}

void sort_deque() {
    if (!front) return;
    // collect into array, sort, write back
    int arr[sz], i = 0;
    struct Node* t = front;
    while (t) { arr[i++] = t->data; t = t->next; }
    // bubble sort
    for (int a = 0; a < sz - 1; a++)
        for (int b = 0; b < sz - a - 1; b++)
            if (arr[b] > arr[b+1]) { int tmp=arr[b]; arr[b]=arr[b+1]; arr[b+1]=tmp; }
    // write back
    t = front; i = 0;
    while (t) { t->data = arr[i++]; t = t->next; }
    printf("Deque sorted\n");
}

void swap_deque(struct Node** f2, struct Node** r2, int* sz2) {
    struct Node* tf = front; front = *f2; *f2 = tf;
    struct Node* tr = rear;  rear  = *r2; *r2 = tr;
    int ts = sz; sz = *sz2; *sz2 = ts;
    printf("Deques swapped\n");
}

// ── Main ──────────────────────────────────────────────────────

int main() {
    // Demo: exercise every operation
    push_back(10);  push_back(20);  push_back(30);
    push_front(5);  push_front(1);
    display();      // 1 5 10 20 30

    get_front();    // 1
    get_back();     // 30
    size();         // 5

    pop_front();    // removes 1
    pop_back();     // removes 30
    display();      // 5 10 20

    reverse();
    display();      // 20 10 5

    push_back(3); push_back(15);
    sort_deque();
    display();      // 3 5 10 15 20

    empty();

    // swap demo
    struct Node* f2 = NULL, *r2 = NULL; int sz2 = 0;
    // build second deque manually by temporarily redirecting globals
    struct Node* save_f = front, *save_r = rear; int save_sz = sz;
    front = rear = NULL; sz = 0;
    push_back(100); push_back(200);
    f2 = front; r2 = rear; sz2 = sz;
    front = save_f; rear = save_r; sz = save_sz;

    printf("Before swap - "); display();
    swap_deque(&f2, &r2, &sz2);
    printf("After swap  - "); display();

    clear();
    empty();

    return 0;
}