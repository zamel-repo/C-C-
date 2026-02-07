#include <stdio.h>
#include <stdlib.h>

int main() {
    //******************** */ malloc() and free() example

    // int number = 0;
    // printf("Enter the number of integers you want to allocate: ");
    // scanf("%d", &number);

    // char *grades = malloc(number * sizeof(char));
    // char *sp = malloc(6 * 4);

    // if(grades == NULL) {
    //     printf("Memory allocation failed!\n");
    //     return 1;
    // }

    // for(int i = 0; i < number; i++) {
    //     printf("Enter grade #%d", i + 1);
    //     scanf(" %c", &grades[i]);
    // }

    // for(int i = 0; i < number; i++) {
    //     printf("\n%c", grades[i]);
    // }


    // free(sp);
    // sp = NULL;
    // free(grades);
    // grades = NULL; // avoid dangling pointer


    //********************************* */ calloc(number , size) = Contiguous Allocation

    int numx = 0;
    printf("Enter the Number of Players: ");
    scanf("%d", &numx);

    int *scores = calloc(numx , sizeof(int));
    if(scores == NULL) {
        printf("Contiguous Allocation Field");
        return 1;
    }

    for(int i = 0; i < numx; i++ ){
        printf("%p ", (void*)&scores[i]);
    }

    free(scores);
    scores = NULL; 

    // realloc(ptr, bytes) = Reallocation.

    int number2 = 0;
    printf("Enter the number of prices: ");
    scanf("%d", &number2);

    float *prices = malloc(number * sizeof(float));

    if(prices == NULL) {
        printf("Memory Allocation Failed!");
        return 1;
    }

    int newNumber = 0;
    printf("Enter a new number of prices: ");
    scanf("%d", &newNumber);

    float *temp = realloc(prices , newNumber * sizeof(float));
    if(temp == NULL) {
        printf("Colud not reallocate memory!\n");
    }
    else {
        prices = temp;
        free(temp);
        temp = NULL;    
    }
    free(prices);
    prices = NULL;

    return 0;
}