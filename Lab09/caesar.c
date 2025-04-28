#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to encrypt a character using Caesar cipher
char encrypt(char ch, int shift) {
    if (!isalpha(ch)) {
        return ch; // Return unchanged if not a letter
    }
    
    char base = islower(ch) ? 'a' : 'A';
    return (char)((((ch - base) + shift) % 26) + base);
}

int main() {
    char filename[100];
    char output_filename[104]; // Original name + ".enc"
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    int shift = 3; // Default shift for Caesar cipher
    
    // Prompt user for the filename
    printf("Enter the name of the file to encrypt: ");
    scanf("%99s", filename);
    
    // Create output filename
    strcpy(output_filename, filename);
    strcat(output_filename, ".enc");
    
    // Open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }
    
    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Cannot create output file %s\n", output_filename);
        fclose(input_file);
        return 1;
    }
    
    // Process the file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            line[i] = encrypt(line[i], shift);
        }
        fputs(line, output_file);
    }
    
    // Close files
    fclose(input_file);
    fclose(output_file);
    
    printf("Encryption complete. Encrypted file saved as %s\n", output_filename);
    
    return 0;
}