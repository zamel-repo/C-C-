#include <stdio.h>
#include <stdbool.h>

void happyBirthDay(char name[], int age) {
    printf("Happy Birthday to you!\n");
    printf("Happy Birthday to you!\n");
    printf("Happy Birthday dear %s.\n", name);
    printf("Happy Birthday to you!\n");

    printf("You are now %d years old!\n", age);
}

int sequare(int number); // function prototype
double cube(double number); // function prototype

int main() {
    char name[50] = "Alice";
    int age = 30;

    int x = 2 * 2;
    int y = x + 4;
    int z = y - 3;
    
    happyBirthDay(name, age);
    return 0;
}
 // function definition
int sequare(int number) {
    int result = number * number;
    return result;
}
 // function definition
double cube(double number) {
    double result = number * number * number;
    return result;
}