#include <stdio.h>
#include <stdbool.h>

int main() {
    int dayOfWeeks = 0;

    printf("Enter a number (1-7) to get the corresponding day of the week: ");
    scanf("%d", &dayOfWeeks);
    switch(dayOfWeeks) {
        case 1: 
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6: 
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n"); 
            break;
        default:
            printf("Invalid day of the week\n");
    }
    return 0;
}