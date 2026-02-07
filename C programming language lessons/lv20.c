#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void swap(int *a, int *b);
int main() {
    int age = 25;
    int *agePtr = &age;

    printf("Value of age variable: %p\n", &age);
    printf("Value via pointer: %d\n", *agePtr);
    printf("the address of age variable: %p\n", (void*)&age);

    int a = 5, b = 10;
    swap(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}

// call by refrence example

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}