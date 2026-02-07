#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    int number = 0;
    
    // While loop
    // while (number < 5) {
    //     printf("Number: %d\n", number);
    //     number++;
    // }
    // // Reset number for next loop
    // do {
    //     printf("Do-While Number: %d\n", number);
    //     number++;
    // }
    // while(number < 10) {
    //     printf("Do-While Number: %d\n", number);
    //     number++;

    // }


    char name[30] = "";
    printf("Enter your NAME: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0'; // ensure null termination

    while(strlen(name) == 0) {
        printf("Name cannot be empty. Please enter your NAME: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0'; // ensure null termination
    }




    bool isRunning = true;
    char response = '\0';

    while(isRunning) {
        printf("Do you want to exit? (Y/N): ");
        scanf(" %c", &response);
        if(response == 'Y' || response == 'y') {
            isRunning = false;
            printf("Exiting the loop.\n");
        } else {
            printf("Continuing the loop.\n");
        }
    }
    return 0;
}