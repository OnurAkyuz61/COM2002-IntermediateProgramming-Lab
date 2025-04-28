#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    int ch;
    
    // Check if exactly two file names are provided
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    
    // Open source file for reading
    source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("Error: Cannot open source file %s\n", argv[1]);
        return 1;
    }
    
    // Open destination file for writing
    destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        printf("Error: Cannot open destination file %s\n", argv[2]);
        fclose(source);
        return 1;
    }
    
    // Copy content character by character
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    
    // Close both files
    fclose(source);
    fclose(destination);
    
    printf("File %s has been copied to %s successfully.\n", argv[1], argv[2]);
    
    return 0;
}