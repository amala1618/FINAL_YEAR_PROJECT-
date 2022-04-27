#include <stdio.h>
#include <stdlib.h>

int main() {
    char sentence[1000];

    // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen("test2.xsm", "w");
    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    	fprintf(fptr, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0); 
    	fprintf(fptr, "BRKP\n");
	fprintf(fptr,"MOV R0, 3\n"); 
	fprintf(fptr,"MOV R1, 2\n");    
	fprintf(fptr,"MOV R2,5\n"); 
	fprintf(fptr,"MOV R3,R0\n"); 
	fprintf(fptr,"GT R3,R1\n"); 
	fprintf(fptr,"JZ R3,2072\n"); 
	fprintf(fptr,"GT R0,R2\n"); 
	fprintf(fptr,"JZ R0, #2068\n"); 
	fprintf(fptr,"MOV R5,R0\n"); 
	fprintf(fptr,"RET\n"); 
	fprintf(fptr,"MOV R5,R2\n"); 
	fprintf(fptr,"RET\n"); 
	fprintf(fptr,"GT R1, R2\n"); 
	fprintf(fptr,"JZ R1, 2082\n"); 
	fprintf(fptr,"MOV R5,R1\n"); 
	fprintf(fptr,"RET\n"); 
	fprintf(fptr,"MOV R5,R2\n"); 
	fprintf(fptr,"RET\n"); 

    	fclose(fptr);
    return 0;
}
