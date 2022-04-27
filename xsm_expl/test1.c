#include <stdio.h>
#include <stdlib.h>

int main() {
    char sentence[1000];

    // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen("test1.xsm", "w");
    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0); 
    fprintf(fptr, "BRKP\n");
    fprintf(fptr, "MOV R0, 2\n");
    fprintf(fptr, "MOV R1, 3\n");
    fprintf(fptr, "SUB R0, R1\n");
    fclose(fptr);
    return 0;
}
