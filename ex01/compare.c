#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 

int main() {
    FILE *fp1, *fp2;
    char path1[100], path2[100];
    char line1[MAX_LEN], line2[MAX_LEN];
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
        exit(1);
    }

    printf("Comparing files...\n");

    while (1) {
        
        char *res1 = fgets(line1, MAX_LEN, fp1);
        char *res2 = fgets(line2, MAX_LEN, fp2);

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
    return 0;
}