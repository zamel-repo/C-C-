#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main() {

    int choice = 0;
    float pounds = 0.0f;
    float kilograms = 0.0f;

    printf("Weight Conversion Menu:\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("Enter weight in Pounds: ");
        scanf("%f", &pounds);
        kilograms = pounds * 0.453592f;
        printf("%.2f Pounds is equal to %.2f Kilograms\n", pounds, kilograms);
    }
    else if (choice == 2) {
        printf("Enter weight in Kilograms: ");
        scanf("%f", &kilograms);
        pounds = kilograms / 0.453592f;
        printf("%.2f Kilograms is equal to %.2f Pounds\n", kilograms, pounds);
    }
    else {
        printf("Invalid choice. Please select 1 or 2.\n");
    }
    return 0;
}
