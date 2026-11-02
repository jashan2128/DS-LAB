#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[35];
    float marks;
};

void displayAll(struct Student *ptr, int n) {
    int i;

    printf("\nRoll\tName\t\tMarks\n");
    printf("---------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%-15s %.2f\n",
               (ptr + i)->roll,
               (ptr + i)->name,
               (ptr + i)->marks);
    }
}

int main(void) {
    int n, i;
    struct Student *students;

    printf("Enter number of students: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    students = malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Enter roll number: ");
        if (scanf("%d", &(students + i)->roll) != 1) {
            printf("Invalid input.\n");
            free(students);
            return 1;
        }

        printf("Enter name: ");
        if (scanf("%34s", (students + i)->name) != 1) {
            printf("Invalid input.\n");
            free(students);
            return 1;
        }

        printf("Enter marks: ");
        if (scanf("%f", &(students + i)->marks) != 1) {
            printf("Invalid input.\n");
            free(students);
            return 1;
        }
    }

    displayAll(students, n);

    free(students);
    return 0;
}
