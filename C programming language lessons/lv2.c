#include <stdio.h>
#include <stdbool.h>

int main() {
    // format specifier examples
    int age  = 25;
    float price = 19.99;
    double pi = 3.141592653589793;
    char currency = '$';
    char name[] = "Ebrahem Alzamel";
    bool isStudent = true;

    printf("your age is: %d years old\n", age);
    printf("the price is: %c%.2f\n", currency, price);
    printf("the value of pi is: %lf\n", pi);
    printf("your name is: %s\n", name);

    if(isStudent) {
        printf("you are a student\n");
    } else {
        printf("you are not a student\n");
    }

    // **************Width

    int num1 = 1;
    int num2 = 25;
    int num3 = 100;

    printf("%3d\n", num2);  // Width of 5
    printf("%-3d\n", num2);  // Width of 5
    printf("%+3d\n", num2);  // Width of 5
    printf("%05d\n", num3);  // Width of 5

    // **************Precision
    float num = 3.14159;
    printf("%.2f\n", num);  // Precision of 2

    // Arthmetic Operators = + - * / % ++ --

    int x = 10;
    printf("x = %d\n", x--);
    printf("x after decrement = %d\n", x);
    return 0;
}

