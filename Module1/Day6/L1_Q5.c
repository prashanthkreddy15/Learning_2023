#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseAndInitialize(struct Student* students, int size, const char* input);
void displayArray(struct Student* students, int size);
void searchByName(struct Student* students, int size, const char* name);

int main() {
    int size, i;
    char input[100];
    char searchName[20];
    struct Student* students;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    students = (struct Student*)malloc(size * sizeof(struct Student));

    printf("Enter the input string: ");
    scanf(" %[^\n]s", input);

    parseAndInitialize(students, size, input);

    printf("\nArray of Students:\n");
    displayArray(students, size);

    printf("\nEnter the name to search: ");
    scanf(" %[^\n]s", searchName);

    searchByName(students, size, searchName);

    free(students);

    return 0;
}

void parseAndInitialize(struct Student* students, int size, const char* input) {
    int i = 0;
    char* token;
    char* rest = (char*)malloc(strlen(input) + 1);
    strcpy(rest, input);

    while ((token = strtok_r(rest, " ", &rest)) != NULL) {
        if (i >= size)
            break;

        students[i].rollno = atoi(token);

        token = strtok_r(rest, " ", &rest);
        strcpy(students[i].name, token);

        token = strtok_r(rest, " ", &rest);
        students[i].marks = atof(token);

        i++;
    }

    free(rest);
}

void displayArray(struct Student* students, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

void searchByName(struct Student* students, int size, const char* name) {
    int i;
    int found = 0;

    for (i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found.\n");
    }
}