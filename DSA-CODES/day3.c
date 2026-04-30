#include <stdio.h>

int main() {
    int n, k, found = 0, comp = 0;

    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        comp++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", comp);

    return 0;
}