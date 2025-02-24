#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s word\n", argv[0]);
        return 1;
    }
    
    char *message = argv[1];
    char letters[100];
    char *p = letters;
    
    // Store only letters (converted to lowercase)
    while (*message) {
        if (isalpha(*message)) {
            *p++ = tolower(*message);
        }
        message++;
    }
    *p = '\0';
    
    // Check if it's a palindrome
    char *start = letters;
    char *end = p - 1;
    
    while (start < end) {
        if (*start++ != *end--) {
            printf("Not a palindrome\n");
            return 0;
        }
    }
    
    printf("Palindrome\n");
    return 0;
}
