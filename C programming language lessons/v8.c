#include <stdio.h>
#include <string.h>
int main() {

    char choice = '\0';
    float fahrenheit = 0.0f;
    float celsius = 0.0f;

    printf("Temperature Conversion Menu:\n");
    printf("A. Fahrenheit to Celsius\n");
    printf("B. Celsius to Fahrenheit\n");
    printf("Enter your choice (C or F): ");
    scanf("%c", &choice);

    if(choice == 'C') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5.0f / 9.0f;
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
    }
    else if (choice == 'F') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9.0f / 5.0f) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
    }
    else {
        printf("Invalid choice. Please select A or B.\n");
    }
    return 0;
}
