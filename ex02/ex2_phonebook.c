#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nom[30];
    char telephone[15];
} Contact;


void createBinaryFile() {
    FILE *f;
    Contact c;
    int n, i;


    f = fopen("agenda.dat", "wb");
    if (!f) { printf("Error creating file!\n"); exit(1); }

    printf("How many contacts to add? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nContact %d:\n", i+1);
        printf("Name: ");
        scanf("%s", c.nom);
        printf("Phone: ");
        scanf("%s", c.telephone);


        fwrite(&c, sizeof(Contact), 1, f);
    }

    printf("\nSaved %d contacts to agenda.dat.\n", n);
    fclose(f);
}


void listBinaryFile() {
    FILE *f;
    Contact c;


    f = fopen("agenda.dat", "rb");
    if (!f) { printf("File not found! Run Create first.\n"); return; }

    printf("\n--- Phonebook List ---\n");


    while(fread(&c, sizeof(Contact), 1, f)) {
        printf("Name: %-15s | Phone: %s\n", c.nom, c.telephone);
    }

    printf("----------------------\n");
    fclose(f);
}


void directAccess() {
    FILE *f;
    Contact c;
    int position;

    f = fopen("agenda.dat", "rb");
    if (!f) { printf("File not found!\n"); return; }

    printf("Which record number do you want to see? (1, 2, 3...): ");
    scanf("%d", &position);

    int offset = (position - 1) * sizeof(Contact);

    // fseek(file, number_of_bytes_to_skip, starting_from_where)
    // SEEK_SET means "Start from the beginning of the file"
    if (fseek(f, offset, SEEK_SET) != 0) {
        printf("Error: Record out of bounds!\n");
    } else {
        // Now that the pointer has jumped, just read one item.
        if (fread(&c, sizeof(Contact), 1, f)) {
            printf("\n--- Record Found ---\n");
            printf("Name: %s\n", c.nom);
            printf("Phone: %s\n", c.telephone);
        } else {
            printf("Error: Could not read record (maybe it doesn't exist).\n");
        }
    }

    fclose(f);
}


int main() {
    int choice;
    do {
        printf("\n=== EXERCISE 2: PHONEBOOK ===\n");
        printf("1. Create/Overwrite File\n");
        printf("2. List All Contacts\n");
        printf("3. Direct Access (Jump to Contact)\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createBinaryFile(); break;
            case 2: listBinaryFile(); break;
            case 3: directAccess(); break;
            case 0: printf("Bye!\n"); break;
            default: printf("Invalid.\n");
        }
    } while (choice != 0);

    return 0;
}
