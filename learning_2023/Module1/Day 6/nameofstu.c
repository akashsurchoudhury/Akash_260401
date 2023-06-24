#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
    char grade;
};

void search_students_by_name(struct Student students[], int numStudents, const char *name) {
    int i, found = 0;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Name: %s, Age: %d, Grade: %c\n", students[i].name, students[i].age, students[i].grade);
            found = 1;
        }
    }

    if (!found) {
        printf("No students found with the name: %s\n", name);
    }
}

int main() {
    struct Student students[MAX_STUDENTS] = {
        {"Alice", 18, 'A'},
        {"Bob", 19, 'B'},
        {"Charlie", 17, 'A'},
        {"Alice", 20, 'B'}
    };
    int numStudents = 4;

    // Search for students named "Alice"
    search_students_by_name(students, numStudents, "Alice");

    return 0;
}
