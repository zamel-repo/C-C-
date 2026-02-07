#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
}Student;

void printStudentInfo(struct Student s);

int main() {
    Student student1 = {"Alice", 20, 3.5, true};
    Student student2 = {0};

    Student students[] = {
        {"Alice", 20, 3.5, true},
        {"Bob", 22, 3.8, false},
        {"Charlie", 19, 3.2, true}
    };

    strcpy(student2.name, "Bob");
    student2.age = 22;
    printStudentInfo(student2);


    
    int size = sizeof(students) / sizeof(students[0]);

    for(int i = 0; i < size; i++) {
        printStudentInfo(students[i]);
    };
    
    return 0;
}

void printStudentInfo(Student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("GPA: %.2f\n", s.gpa);
    printf("Full-time: %s\n", s.isFullTime ? "Yes" : "No");
}