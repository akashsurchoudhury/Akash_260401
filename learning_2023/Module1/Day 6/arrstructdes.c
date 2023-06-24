#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudentsByMarks(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
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

    printf("\nEnter details of students:\n");
    for (int i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollno);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\nStudents before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    sortStudentsByMarks(students, size);

    printf("\nStudents after sorting (descending order by marks):\n");
    for (int i = 0; i < size; i++) {
        printf("Roll Number: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);
    return 0;
}

