#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &stack[i]);

    for (int i = n - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}