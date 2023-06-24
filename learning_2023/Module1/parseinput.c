#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseAndInitialize(struct Student* students, int size, const char* input) {
    char temp[20];
    int i = 0;
    int j = 0;
    int count = 0;

    while (input[i] != '\0') {
        if (input[i] != ' ') {
            temp[j++] = input[i];
        } else {
            temp[j] = '\0';

            switch (count) {
                case 0:
                    students[size].rollno = atoi(temp);
                    break;
                case 1:
                    strcpy(students[size].name, temp);
                    break;
                case 2:
                    students[size].marks = atof(temp);
                    break;
                default:
                    break;
            }

            memset(temp, 0, sizeof(temp));
            j = 0;
            count++;
        }

        i++;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    printf("\nEnter student details:\n");

    for (int i = 0; i < size; i++) {
        char input[50];
        printf("Enter details for student %d: ", i + 1);
        scanf(" %[^\n]", input);
        parseAndInitialize(students, i, input);
    }

    printf("\nStudent Details:\n");

    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);

    return 0;
}
