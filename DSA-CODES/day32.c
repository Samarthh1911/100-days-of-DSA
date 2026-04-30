#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int stack[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &stack[i]);
    
    int m;
    scanf("%d", &m);
    
    int top = n - m - 1;
    
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    
    return 0;
}