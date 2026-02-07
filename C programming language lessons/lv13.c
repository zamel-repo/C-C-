#include <stdio.h>

int main() {
    // for loop

    for(int i = 0; i < 5; i++) {
        printf("For Loop Iteration: %d\n", i);

        if(i == 3) {
            printf("Breaking out of the loop at iteration %d\n", i);
            break;
        }

        if(i == 1) {
            printf("Continuing to next iteration at %d\n", i);
            continue;
        }
    }

    return 0;
}