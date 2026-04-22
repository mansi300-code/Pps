#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fpData, *fpOdd, *fpEven;
    int num;

    // Open input file
    fpData = fopen("data.txt", "r");

    if(fpData == NULL) {
        printf("Error: data file not found!\n");
        return 1;
    }

    // Open output files
    fpOdd = fopen("odd.txt", "w");
    fpEven = fopen("even.txt", "w");

    if(fpOdd == NULL || fpEven == NULL) {
        printf("Error creating output files!\n");
        fclose(fpData);
        return 1;
    }

    // Read numbers and separate
    while(fscanf(fpData, "%d", &num) != EOF) {
        if(num % 2 == 0) {
            fprintf(fpEven, "%d ", num);
        } else {
            fprintf(fpOdd, "%d ", num);
        }
    }

    fclose(fpData);
    fclose(fpOdd);
    fclose(fpEven);

    // Display Odd numbers
    printf("\nOdd numbers:\n");
    fpOdd = fopen("odd.txt", "r");

    while(fscanf(fpOdd, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    fclose(fpOdd);

    // Display Even numbers
    printf("\nEven numbers:\n");
    fpEven = fopen("even.txt", "r");

    while(fscanf(fpEven, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    fclose(fpEven);

    return 0;
}
