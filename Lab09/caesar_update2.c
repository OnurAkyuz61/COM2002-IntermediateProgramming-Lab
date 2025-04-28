#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to decrypt a character using Caesar cipher
char decrypt(char ch, int shift) {
    if (!isalpha(ch)) {
        return ch; // Return unchanged if not a letter
    }
    
    char base = islower(ch) ? 'a' : 'A';
    // Add 26 to ensure positive result after modulo
    return (char)((((ch - base) - shift + 26) % 26) + base);
}

int main(int argc, char *argv[]) {
    char output_filename[104]; // For decrypted file
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    int shift = 3; // Default shift for Caesar cipher
    char *enc_extension;
    
    // Check if filename is provided as command line argument
    if (argc != 2) {
        printf("Usage: %s <encrypted_filename>\n", argv[0]);
        return 1;
    }
    
    // Check if file has .enc extension
    enc_extension = strstr(argv[1], ".enc");
    if (enc_extension == NULL || strcmp(enc_extension, ".enc") != 0) {
        printf("Error: File must have .enc extension\n");
        return 1;
    }
    
    // Create output filename (remove .enc extension)
    strncpy(output_filename, argv[1], strlen(argv[1]) - 4); // Remove .enc
    output_filename[strlen(argv[1]) - 4] = '\0'; // Ensure null termination
    strcat(output_filename, ".dec"); // Add .dec extension
    
    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
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
            line[i] = decrypt(line[i], shift);
        }
        fputs(line, output_file);
    }
    
    // Close files
    fclose(input_file);
    fclose(output_file);
    
    printf("Decryption complete. Decrypted file saved as %s\n", output_filename);
    
    return 0;
}
