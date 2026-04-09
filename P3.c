#include <stdio.h>

// Recursive function
long long int factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

// Iterative function
long long int factorialIterative(int n) {
    long long int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, choice;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Edge case: negative number
    if (n < 0) {
        printf("Factorial is not defined for negative numbers!\n");
        return 0;
    }

    // Edge case: very large number (overflow warning)
    if (n > 20) {
        printf("Warning: Result may overflow for n > 20!\n");
    }

    printf("\nChoose method:\n");
    printf("1. Iterative\n");
    printf("2. Recursive\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Factorial (Iterative) = %lld\n", factorialIterative(n));
            break;

        case 2:
            printf("Factorial (Recursive) = %lld\n", factorialRecursive(n));
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
