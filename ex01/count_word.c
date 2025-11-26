#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main() {
    FILE *fptr;
    char wordInFile[100]; 
    char targetWord[100]; 
    int count = 0;

    
    printf("Enter the word to search for: ");
    scanf("%s", targetWord);

    fptr = fopen("data.txt", "r"); 
    if (fptr == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }


    while (fscanf(fptr, "%s", wordInFile) != EOF) {
        
        if (strcmp(wordInFile, targetWord) == 0) {
            count++;
        }
    }

    printf("The word '%s' appears %d times.\n", targetWord, count);

    fclose(fptr);
    return 0;
}