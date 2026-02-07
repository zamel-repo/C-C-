#include <stdio.h>
#include <stdbool.h>

typedef int Number;
typedef char* String;
typedef float Decimal;
typedef unsigned long ulong;

int main() {

    String greeting[] = {"Hello, World!", "Hi there!", "Greetings!"};
    printf("%s\n", greeting[0]);


    // ternary operator ?
    /*
        shorthand for if-else statement 
        ( condition ) ? expression_if_true : expression_if_false;
    */
    int x = 5;
    int y = 6;
    int max = (x > y) ? x : y;
    printf("The maximum value is: %d\n", max);


    bool isOnline = false;
    (isOnline) ? printf("User is online\n") : printf("User is offline\n");


    int hours = 10;
    int minutes = 30;
    char *timeOfDay = (hours < 12) ? "AM" : "PM";
    printf("The time is: %02d:%02d %s\n", hours, minutes, timeOfDay); 

    return 0;
}