#include <stdio.h>
#include <stdbool.h>

void setColor(int color) {
    printf("\033[%dm", color);
}

int main() {

    return 0;
}
