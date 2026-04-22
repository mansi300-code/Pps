#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50], data[200];
    int choice;

    while(1) {
        printf("\nSimple Text Editor:\n");
        printf("1 - Create & Write to file\n");
        printf("2 - Read file\n");
        printf("3 - Append to file\n");
        printf("4 - Delete file contents\n");
        printf("5 - Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch(choice) {

            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                getchar();

                fp = fopen(filename, "w");

                if(fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }

                printf("Enter data to write:\n");
                fgets(data, sizeof(data), stdin);

                fputs(data, fp);
                fclose(fp);

                printf("File created and data written successfully.\n");
                break;

            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");

                if(fp == NULL) {
                    printf("File does not exist or cannot be opened!\n");
                    break;
                }

                printf("File contents:\n");
                while(fgets(data, sizeof(data), fp) != NULL) {
                    printf("%s", data);
                }

                fclose(fp);
                break;

            case 3:
                printf("Enter filename: ");
                scanf("%s", filename);
                getchar();

                fp = fopen(filename, "a");

                if(fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }

                printf("Enter data to append:\n");
                fgets(data, sizeof(data), stdin);

                fputs(data, fp);
                fclose(fp);

                printf("Data appended successfully.\n");
                break;

            case 4:
                printf("Enter filename: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");

                if(fp == NULL) {
                    printf("Error clearing file!\n");
                    break;
                }

                fclose(fp);
                printf("File contents deleted successfully.\n");
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
