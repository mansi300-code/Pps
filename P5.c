#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int size = 0, choice, newSize, i;

    while(1) {
        printf("\nDynamic Array Operations:\n");
        printf("1 - Create array (malloc)\n");
        printf("2 - Add elements\n");
        printf("3 - Resize array (realloc)\n");
        printf("4 - Display array\n");
        printf("5 - Free memory & Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(arr != NULL) {
                    printf("Array already exists! Free it first.\n");
                    break;
                }

                printf("Enter number of elements: ");
                scanf("%d", &size);

                if(size <= 0) {
                    printf("Invalid size!\n");
                    break;
                }

                arr = (int*) malloc(size * sizeof(int));

                if(arr == NULL) {
                    printf("Memory allocation failed!\n");
                } else {
                    printf("Memory allocated successfully.\n");
                }
                break;

            case 2:
                if(arr == NULL) {
                    printf("Create array first!\n");
                    break;
                }

                printf("Enter %d elements:\n", size);
                for(i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 3:
                if(arr == NULL) {
                    printf("Create array first!\n");
                    break;
                }

                printf("Enter new size: ");
                scanf("%d", &newSize);

                if(newSize <= 0) {
                    printf("Invalid size!\n");
                    break;
                }

                int *temp = (int*) realloc(arr, newSize * sizeof(int));

                if(temp == NULL) {
                    printf("Reallocation failed!\n");
                } else {
                    arr = temp;
                    size = newSize;
                    printf("Array resized successfully.\n");
                }
                break;

            case 4:
                if(arr == NULL) {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Array elements:\n");
                for(i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 5:
                free(arr);
                arr = NULL;
                printf("Memory freed successfully. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
