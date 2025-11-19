#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- FUNCTION DECLARATIONS ---
// (This tells C that these functions exist somewhere below)
void showContent();
void countWord();
void concatFiles();
void countLines();
void compareFiles();

// --- MAIN PROGRAM ---
int main() {
    int choice;

    do {
        // 1. Clear screen (Arch/Linux specific command)
        // system("clear"); 
        
        // 2. Print the Menu based on your TP
        printf("\n=================================\n");
        printf("      ESI SBA - TP FILES MENU    \n");
        printf("=================================\n");
        printf("1. Display file content\n");
        printf("2. Count word occurrence\n");
        printf("3. Concatenate two files\n");
        printf("4. Count lines in file\n");
        printf("5. Compare two files\n");
        printf("0. Exit\n");
        printf("=================================\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        
        // PRO TIP: 'scanf' leaves the Enter key (\n) in the buffer.
        // This loop eats that character so it doesn't break your next input.
        while(getchar() != '\n'); 

        // 3. Switch Case
        switch(choice) {
            case 1:
                showContent();
                break;
            case 2:
                countWord();
                break;
            case 3:
                concatFiles();
                break;
            case 4:
                countLines();
                break;
            case 5:
                compareFiles();
                break;
            case 0:
                printf("Exiting... Bye bro.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

// --- YOUR LOGIC GOES BELOW ---

// Exercise 1.1: Display Content
void showContent() {
    printf("\n--- Display File Content ---\n");
    // PASTE YOUR CODE FROM 'ex1_q1.c' HERE
    // (Remove the 'int main' and 'return 0' parts, keep the variables and logic)
    
    // Example quick implementation:
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE *f = fopen(filename, "r");
    if (!f) { printf("Error opening file.\n"); return; }
    
    char c;
    while ((c = fgetc(f)) != EOF) printf("%c", c);
    
    fclose(f);
    printf("\n");
}

// Exercise 1.2: Count Word
void countWord() {
    printf("\n--- Count Word Occurrence ---\n");
    
    FILE *fptr;
    char wordInFile[100]; 
    char targetWord[100]; 
    int count = 0;

    printf("Enter the word to search for: ");
    scanf("%s", targetWord);

    fptr = fopen("data.txt", "r"); 
    if (fptr == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    while (fscanf(fptr, "%s", wordInFile) != EOF) {
        if (strcmp(wordInFile, targetWord) == 0) {
            count++;
        }
    }

    printf("The word '%s' appears %d times.\n", targetWord, count);

    fclose(fptr);
}

// Exercise 1.3: Concatenate
void concatFiles() {
    printf("\n--- Concatenate Files ---\n");
    
    FILE *f1, *f2, *f_out;
    char file1_name[100], file2_name[100], output_name[100];

    printf("Enter name of first file: ");
    scanf("%s", file1_name);
    
    printf("Enter name of second file: ");
    scanf("%s", file2_name);

    printf("Enter name of the new combined file: ");
    scanf("%s", output_name);

    f1 = fopen(file1_name, "r");
    f2 = fopen(file2_name, "r");

    if (f1 == NULL || f2 == NULL) {
        printf("Error: One of the input files doesn't exist!\n");
        return;
    }

    f_out = fopen(output_name, "w");

    printf("Merging files...\n");
    
    // Copy first file
    char c;
    while ((c = fgetc(f1)) != EOF) {
        fputc(c, f_out);
    }
    
    // Copy second file
    while ((c = fgetc(f2)) != EOF) {
        fputc(c, f_out);
    }

    printf("Success! Check %s for the result.\n", output_name);

    fclose(f1);
    fclose(f2);
    fclose(f_out);
}

// Exercise 1.4: Count Lines
void countLines() {
    printf("\n--- Count Lines ---\n");
    
    FILE *fptr;
    char filename[100];
    char c;
    int lines = 0;
    
    printf("Enter filename to count lines: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    while ((c = fgetc(fptr)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    
    printf("The file %s has %d lines.\n", filename, lines+1);

    fclose(fptr);
}

// Exercise 1.5: Compare Files
void compareFiles() {
    printf("\n--- Compare Files ---\n");
    
    FILE *fp1, *fp2;
    char path1[100], path2[100];
    char line1[1000], line2[1000];
    int lineNum = 1;
    int diffFound = 0;

    printf("Enter first file path: ");
    scanf("%s", path1);
    printf("Enter second file path: ");
    scanf("%s", path2);

    fp1 = fopen(path1, "r");
    fp2 = fopen(path2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: One or both files could not be opened.\n");
        return;
    }

    printf("Comparing files...\n");

    while (1) {
        char *res1 = fgets(line1, 1000, fp1);
        char *res2 = fgets(line2, 1000, fp2);

        if (res1 == NULL && res2 == NULL) {
            printf("\nResult: Files are IDENTICAL.\n");
            break;
        }

        if (res1 == NULL && res2 != NULL) {
            printf("\nDifference at Line %d:\n", lineNum);
            printf("File 1: [End of File]\n");
            printf("File 2: %s", line2);
            diffFound = 1;
            break;
        }
        if (res1 != NULL && res2 == NULL) {
            printf("\nDifference at Line %d:\n", lineNum);
            printf("File 1: %s", line1);
            printf("File 2: [End of File]\n");
            diffFound = 1;
            break;
        }

        if (strcmp(line1, line2) != 0) {
            printf("\nDifference found at Line %d:\n", lineNum);
            printf("File 1 says: %s", line1);
            printf("File 2 says: %s", line2);
            diffFound = 1;
            break;
        }

        lineNum++;
    }

    fclose(fp1);
    fclose(fp2);
}