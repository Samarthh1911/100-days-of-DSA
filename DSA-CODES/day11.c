#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[m][n], b[m][n], sum[m][n];

    // first matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // second matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}