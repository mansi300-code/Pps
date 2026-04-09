#include <stdio.h>
#include <string.h>

#define MAX 100

// -------- ARRAY FUNCTIONS --------

// Sorting (Bubble Sort)
void sortArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Searching (Linear Search)
void searchArray(int arr[], int n) {
    int key, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found!\n");
}

// -------- STRING FUNCTIONS --------

// Concatenation
void concatStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

// Comparison
void compareStrings(char str1[], char str2[]) {
    int result = strcmp(str1, str2);

    if (result == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");
}

// -------- MAIN --------
int main() {
    int choice, type;

    printf("Select type:\n1. Array Operations\n2. String Operations\nEnter choice: ");
    scanf("%d", &type);

    if (type == 1) {
        int arr[MAX], n;

        printf("Enter number of elements: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX) {
            printf("Invalid array size!\n");
            return 0;
        }

        printf("Enter elements:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("\n1. Sort Array\n2. Search Element\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: sortArray(arr, n); break;
            case 2: searchArray(arr, n); break;
            default: printf("Invalid choice!\n");
        }
    }

    else if (type == 2) {
        char str1[100], str2[100];

        printf("Enter first string: ");
        scanf("%s", str1);

        printf("Enter second string: ");
        scanf("%s", str2);

        printf("\n1. Concatenate\n2. Compare\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: concatStrings(str1, str2); break;
            case 2: compareStrings(str1, str2); break;
            default: printf("Invalid choice!\n");
        }
    }

    else {
        printf("Invalid selection!\n");
    }

    return 0;
}
