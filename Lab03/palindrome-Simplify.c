#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    char letters[MAX_LENGTH];
    char *p;
    
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    // Store only letters (converted to lowercase) in the letters array
    for (p = letters; *message != '\0' && *message != '\n'; message++) {
        if (isalpha(*message)) {
            *p++ = tolower(*message);
        }
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
