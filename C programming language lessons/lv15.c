#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    char name[] = "Bro Code";
    int scores[5] = {0}; // initialize all elements to 0 

    int sum = 0;

    int size = sizeof(numbers) / sizeof(numbers[0]);
    for(int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    printf("%d ", numbers);
    return 0;
}