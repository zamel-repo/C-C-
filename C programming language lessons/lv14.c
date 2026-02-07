#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int randomInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand((unsigned) time(NULL));

    int r = randomInRange(1, 100);
    printf("%d\n", r);

    ////////////////////

       int fd = open("/dev/urandom", O_RDONLY);

    unsigned int num;
    read(fd, &num, sizeof(num));
    close(fd);

    int min = 1, max = 100;
    int randNum = min + (num % (max - min + 1));

    printf("%d\n", randNum);
    return 0;
}
