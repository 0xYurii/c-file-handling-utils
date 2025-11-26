#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[100];
    char c;
    int lines = 0;
    
    
    printf("Enter filename to count lines: ");
    scanf("%s", filename);

    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    
    while ((c = fgetc(fptr)) != EOF) {
        
        if (c == '\n') {
            lines++;
        }
    }
    printf("The file %s has %d lines.\n", filename, lines+1);

    fclose(fptr);
    return 0;
}