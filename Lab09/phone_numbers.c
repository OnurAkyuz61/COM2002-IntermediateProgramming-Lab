#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char line[100];
    char digits[11] = {0}; // 10 digits + null terminator
    
    // Check if filename is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // Open the file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    
    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        int digit_count = 0;
        
        // Extract digits from the line
        for (int i = 0; line[i] != '\0' && digit_count < 10; i++) {
            if (isdigit(line[i])) {
                digits[digit_count++] = line[i];
            }
        }
        
        // If we found 10 digits, format and print them
        if (digit_count == 10) {
            printf("(%c%c%c) %c%c%c-%c%c%c%c\n",
                   digits[0], digits[1], digits[2],
                   digits[3], digits[4], digits[5],
                   digits[6], digits[7], digits[8], digits[9]);
        }
        
        // Reset digits array for next line
        for (int i = 0; i < 11; i++) {
            digits[i] = 0;
        }
    }
    
    fclose(file);
    return 0;
}
