#include <stdio.h>
#include <string.h>

int main() {
    // Write a file

    // FILE *Pfile = fopen("test.txt", "w");
    // char text[] = "Hello, World! \nBOOTY BOOTY BOOTY";

    // if(Pfile == NULL) {
    //     printf("Error opening file!\n");
    //     return 1;
    // }

    // fprintf(Pfile, "%s\n", text);
    // fprintf(Pfile, "%s\n", "Appending another line.");
    // printf("File written successfully.\n");


    // Read the file

    FILE *pFile = fopen("test.txt", "r");
    if(pFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char buffer[1024] = {0};
    while(fgets(buffer, sizeof(buffer), pFile) != NULL) {
        buffer[strlen(buffer) - 1] = '\0'; // Remove newline character
        
        printf("-%s", buffer);
        printf("----------------\n");
        for(int i = 0; buffer[i] != '\0'; i++) {
            printf("[%c]", buffer[i]);
        }
        printf("\n----------------\n");
    }
    fclose(pFile);
    return 0;
}