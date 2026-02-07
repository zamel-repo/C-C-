#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// the main function is entry point :)
int main() {
    /*
        This is a simple C program that prints two lines to the console.
        1. "I like Pizza!"
        2. "It's really good!"
    */
    printf("I like Pizza! \n");
    printf("It's really good!");

    // Example of variable declaration and usage
    // int number; // Variable declaration
    int number = 42; // Example variable declaration
    printf("\n the answer is %d \n ", number);

    int age = 24;
    printf("I'm %d years old \n", age);
    // float number = 3.14; // Variable declaration
    float gpa = 3.5;
    float pi = 3.14;
    printf("my gpa is %f, pi math is %.1f\n", gpa, pi);

    // double precision example
    double pil = 3.141592653589793;
    double e = 2.718281828459045;
    printf("the value of pi is %.15lf\n", pil); 
    printf("the value of e is %.10lf\n", e);

    // character example
    char grade = 'A';
    printf("my grade is %c\n", grade);
    char symbol = '#';
    printf("your favorite symblo is %c\n", symbol);

    char name[] = "Ebrahem Alzamel";
    char food[] = "Pizza";
    char userName[] = "Ebrahem123";
    char email[100];

    sprintf(email, "%s@gmail.com", userName);

    printf("my name is ' %s '\n", name);
    printf("my favorite food is %s \n", food);
    printf("my email is %s \n", email);
    // bool example
    bool isSecured = true;
    bool isOnline = false;
    bool isAdmin = true;
    bool hasAccess = false;

    printf("isSecured: %d \n", isSecured);
    printf("isOnline: %d \n", isOnline);

    if(isOnline) {
        printf("you r online \n");
    }
    else {
        printf("you r offline \n");
    } 





    // system("pause");



    return 0;
}