#include <stdio.h>

void swap(int arr[], int i, int j) {
    int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
}

// ── Heapify Down: maintain max heap property ──────────────────
void heapify(int arr[], int n, int i) {
    int large = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left  < n && arr[left]  > arr[large]) large = left;
    if (right < n && arr[right] > arr[large]) large = right;

    if (large != i) {
        swap(arr, i, large);
        heapify(arr, n, large);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build max heap (bottom-up from last non-leaf)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract max one by one, place at end
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);      // move current root (max) to end
        heapify(arr, i, 0);   // heapify reduced heap
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}