#include <stdio.h>

int main() {
    // int _2d[3][3] = {0};

    // int numbers [][3] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {9, 9 , 7}
    // };

    // printf("%d\n", numbers[0][0]);

    // for(int row = 0; row < 3; row++) {
    //     for(int col = 0; col < 3; col++) {
    //        printf("%d ", _2d[row][col]);
    //     }
    //     printf("\n");
    // }

    // printf("\n %d", sizeof(numbers) / sizeof(numbers[0]));


    // char fruits[][10] = {"Apple", "Banana", "Coconut"};
    // char fruits[][10]= {
    //     {'A', 'p', 'p', 'l', 'e', '\0', '\0', '\0', '\0', '\0'},
    //     { 'B', 'a', 'n', 'a', 'n', 'a', '\0', '\0', '\0', '\0'},
    //     {'C', 'o', 'c', 'o', 'n', 'u', 't', '\0', '\0', '\0'}
    // };

    // fruits[0][0] = 'a';

    // for(int i = 0; i < 3; i++) {
    //     printf("%s\n", fruits[i]);
    // }


    char questions[][100] = {
        "What is your name?",
        "What is your favorite color?",
        "What is your quest?"
    };

    char options[][3][60] = {
        {"Alice", "Bob", "Charlie"},
        {"Red", "Blue", "Green"},
        {"To seek the Holy Grail", "To find a shrubbery", "To rescue the princess"}
    };

    char options2[][100] = {"A. Jupiter\nB. Saturate\nC. Neptune"};

    printf("%s\n", questions[0]);
    printf("%s\n%s\n%s\n", options[0][0], options[0][1], options[0][2]);
    printf("%s\n", options2[0]);
    return 0;
}