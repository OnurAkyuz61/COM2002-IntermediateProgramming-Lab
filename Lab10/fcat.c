#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int ch;
    
    // Check if at least one file is specified
    if (argc < 2) {
        printf("Usage: %s file1 [file2 file3 ...]\n", argv[0]);
        return 1;
    }
    
    // Process each file specified on the command line
    for (int i = 1; i < argc; i++) {
        // Open the file
        file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Error: Cannot open file %s\n", argv[i]);
            return 1;
        }
        
        // Read and write the file contents to standard output
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        
        // Close the file
        fclose(file);
    }
    
    return 0;
}
