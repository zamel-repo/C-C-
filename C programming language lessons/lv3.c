#include<stdio.h>
#include<string.h>

int main() {
    char name[30] = "";
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0'; // null terminator
    double pi = 0.0;

    printf("Enter your AGE: ");
    scanf("%d", &age);

    printf("Enter your GPA: ");
    scanf("%f", &gpa);

    
    printf("Enter your GRADE: ");
    scanf(" %c", &grade);

    // delete newline character from input buffer ( \n ) -> (  ) 
    getchar();
    printf("Enter your NAME: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character if present
    name[strlen(name) - 1] = '\0'; // ensure null termination

    printf("\n");
    printf("Your Name is:%s\n", name);
    printf("Your GPA is:%.2f\n", gpa);
    printf("Your Grade is:%c\n", grade);
    printf("The value of PI is:%.10lf\n", pi);
    printf("Your Age is:%d", age);
    printf("\n");
}