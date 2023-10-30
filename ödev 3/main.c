#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student information
struct Student {
    int number;
    char name[50];
    int age;
    struct Student *next;
};

// Function to traverse the linked list and display student information
void showStudentList(struct Student *start) {
    int count = 0;
    while (start != NULL) {
        count++;
        printf("%d- %s %d %d\n", count, start->name, start->age, start->number);
        start = start->next;
    }
}

int main() {
    struct Student *start = NULL;
    struct Student *previous = NULL;
    int continueInput = 1;

    while (continueInput) {
        struct Student *student = (struct Student *)malloc(sizeof(struct Student));

        printf("Student Number: ");
        scanf("%d", &student->number);

        printf("Student Name: ");
        scanf("%s", student->name);

        printf("Student Age: ");
        scanf("%d", &student->age);

        student->next = NULL;

        if (start == NULL) {
            start = student;
        } else {
            previous->next = student;
        }

        previous = student;

        printf("Do you want to add another student? (Yes: 1, No: 0): ");
        scanf("%d", &continueInput);
    }

    // Display the student list
    showStudentList(start);

    // Clean up memory
    struct Student *current = start;
    while (current != NULL) {
        struct Student *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
