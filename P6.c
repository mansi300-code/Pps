#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure
struct Student {
    char name[50];
    int rollNo;
    float marks;
};

struct Student s[MAX];
int count = 0;

// Add Students
void addStudent() {
    int n;

    printf("How many students to add: ");
    scanf("%d", &n);

    if (n <= 0 || count + n > MAX) {
        printf("Invalid number or storage full!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", count + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", s[count].name);

        printf("Enter roll number: ");
        scanf("%d", &s[count].rollNo);

        printf("Enter marks: ");
        scanf("%f", &s[count].marks);

        if (s[count].marks < 0 || s[count].marks > 100) {
            printf("Invalid marks! Try again.\n");
            i--;
            continue;
        }

        count++;
    }
}

// Display Students
void displayStudents() {
    if (count == 0) {
        printf("No records available!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Roll Number: %d\n", s[i].rollNo);
        printf("Marks: %.2f\n", s[i].marks);
    }
}

// Search Student
void searchStudent() {
    int roll, found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            printf("Found: %s, Marks: %.2f\n", s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");
}

// Modify Student
void modifyStudent() {
    int roll, found = 0;

    printf("Enter roll number to modify: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            printf("Enter new name: ");
            scanf(" %[^\n]", s[i].name);

            printf("Enter new marks: ");
            scanf("%f", &s[i].marks);

            if (s[i].marks < 0 || s[i].marks > 100) {
                printf("Invalid marks!\n");
                return;
            }

            printf("Record updated!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");
}

// Delete Student
void deleteStudent() {
    int roll, found = 0;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("Record deleted!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");
}

// Main Menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Students\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Modify Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: modifyStudent(); break;
            case 5: deleteStudent(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
