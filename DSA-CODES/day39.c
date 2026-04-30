#include <stdio.h>
#include <string.h>

int heap[100], size = 0;

void swap(int i, int j) {
    int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
}

// ── Heapify Up: fix after insert ──────────────────────────────
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) { swap(parent, i); i = parent; }
        else break;
    }
}

// ── Heapify Down: fix after extract ──────────────────────────
void heapifyDown(int i) {
    while (1) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int small = i;

        if (left  < size && heap[left]  < heap[small]) small = left;
        if (right < size && heap[right] < heap[small]) small = right;

        if (small != i) { swap(i, small); i = small; }
        else break;
    }
}

void insert(int val) {
    heap[size++] = val;
    heapifyUp(size - 1);
}

void extractMin() {
    if (size == 0) { printf("-1\n"); return; }
    printf("%d\n", heap[0]);
    heap[0] = heap[--size];   // move last to root
    heapifyDown(0);
}

void peek() {
    if (size == 0) { printf("-1\n"); return; }
    printf("%d\n", heap[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[15];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int val; scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}