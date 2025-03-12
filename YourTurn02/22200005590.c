#define _CRT_SECURE_NO_WARNINGS // for Visual Studio compiler

#include <stdio.h> // for printf(), scanf()
#include <string.h> // for strlen()
#include <ctype.h> // for toupper()

#define MAX_LENGTH 1000 // maximum length of a word

// Function to calculate letter frequencies using pointers
void calculateFrequency(char *text, double *frequency) {
    // Initialize counter for total letters
    int totalLetters = 0;

    // Count occurrences of each letter
    while (*text) {
        // Convert character to uppercase for case-insensitive counting
        char c = toupper(*text);

        // Check if character is a letter
        if (c >= 'A' && c <= 'Z') {
            // Increment the count for this letter
            frequency[c - 'A']++;
            totalLetters++;
        }
        text++;
    }

    // Calculate relative frequency for each letter
    for (int i = 0; i < 26; i++) {
        if (totalLetters > 0) {
            frequency[i] = frequency[i] / totalLetters;
        }
    }
}

int main() {
    // Declare variables
    char text[MAX_LENGTH];
    double frequency[26] = {0}; // Array to store frequency of each letter

    // Prompt user for input
    printf("Enter a paragraph: ");
    fgets(text, MAX_LENGTH, stdin);

    // Calculate frequencies
    calculateFrequency(text, frequency);

    // Display results
    printf("\nLetter Frequency:\n");
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            printf("%c: %.4f\n", 'A' + i, frequency[i]);
        }
    }

    return 0;
}
