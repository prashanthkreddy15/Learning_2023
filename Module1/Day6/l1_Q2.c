#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseAndInitialize(struct Student* students, int size, const char* input);
void initializeArray(struct Student* students, int size);

int main() {
    int size, i;
    char input[100];
    struct Student* students;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    students = (struct Student*)malloc(size * sizeof(struct Student));

    printf("Enter the input string: ");
    scanf(" %[^\n]s", input);

    parseAndInitialize(students, size, input);

    printf("\nArray of Students:\n");
    for (i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

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

void initializeArray(struct Student* students, int size) {
    int i;
    for (i = 0; i < size; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}