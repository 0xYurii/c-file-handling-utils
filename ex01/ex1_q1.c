#include <stdio.h>
#include <stdlib.h> 

int main() {
    FILE *fptr; 
    char c;    


    fptr = fopen("data.txt", "r");


    if (fptr == NULL) {
        printf("Error: Could not open file. Did you create data.txt?\n");
        exit(1); 
    }

    printf("--- File Contents Below ---\n");
    
    c = fgetc(fptr); 
    while ( c != EOF ) { 
        
        printf("%c", c);
        
        
        c = fgetc(fptr);
    }

    printf("\n--- End of File ---\n");


    fclose(fptr);

    return 0;
}