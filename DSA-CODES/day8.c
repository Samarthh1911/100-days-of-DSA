#include <stdio.h>

// Recursive function using Binary Exponentiation logic
long long power(int a, int b) {
    // Base case: any number raised to the power of 0 is 1
    if (b == 0) {
        return 1;
    }
    
    // Recursive call: compute a^(b/2) once to save time
    long long half = power(a, b / 2);
    
    // If b is even: a^b = a^(b/2) * a^(b/2)
    if (b % 2 == 0) {
        return half * half;
    } 
    // If b is odd: a^b = a * a^(b/2) * a^(b/2)
    else {
        return a * half * half;
    }
}

int main() {
    int a, b;
    // Input two space-separated integers
    if (scanf("%d %d", &a, &b) == 2) {
        // Output the result
        printf("%lld\n", power(a, b));
    }
    return 0;
}