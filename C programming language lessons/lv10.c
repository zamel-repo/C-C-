#include <stdio.h>
#include <stdbool.h>

int main() {
    float price = 10.00;
    bool isStudent = true;
    bool isSenior = false;

    
    if(isStudent) {
        printf("Original Price: $%.2f\n", price);
        price = price * 0.8f; // 20% discount for students
    }

    if(isSenior) {
        printf("Original Price: $%.2f\n", price);
        price = price * 0.85f; // 15% discount for seniors
    }

    printf("Final Price: $%.2f\n", price);
}