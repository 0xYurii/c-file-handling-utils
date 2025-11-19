#include <stdio.h>
#include <stdlib.h>

void copyContent(FILE *source, FILE *destination) {
    char c;
    
    while ((c = fgetc(source)) != EOF) {
        
        fputc(c, destination);
    }
}

int main() {
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
        exit(1);
    }

    
    f_out = fopen(output_name, "w");

    
    printf("Merging files...\n");
    
    copyContent(f1, f_out); 
    copyContent(f2, f_out); 

    printf("Success! Check %s for the result.\n", output_name);

   
    fclose(f1);
    fclose(f2);
    fclose(f_out);

    return 0;
}