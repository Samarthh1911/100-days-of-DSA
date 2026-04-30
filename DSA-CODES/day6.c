#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    // Get the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: empty or single element array
    if (n == 1) {
        printf("%d\n", arr[0]);
        free(arr);
        return 0;
    }

    // Two-pointer logic
    int i = 0; // Pointer to the last unique element
    for (int j = 1; j < n; j++) {
        // If we find a new unique element
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    // Output the unique elements
    for (int k = 0; k <= i; k++) {
        printf("%d%s", arr[k], (k == i ? "" : " "));
    }
    printf("\n");

    free(arr);
    return 0;
}