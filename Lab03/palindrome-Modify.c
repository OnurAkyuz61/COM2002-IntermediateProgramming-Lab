#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    char letters[MAX_LENGTH];
    char *p = letters;
    
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    // Store only letters (converted to lowercase) in the letters array
    for (char *m = message; *m != '\0' && *m != '\n'; m++) {
        if (isalpha(*m)) {
            *p++ = tolower(*m);
        }
    }
    *p = '\0';
    
    // Check if it's a palindrome
    int is_palindrome = 1;
    char *start = letters;
    char *end = p - 1;  // p points to '\0', so end should point to last char
    
    while (start < end) {
        if (*start != *end) {
            is_palindrome = 0;
            break;
        }
        start++;
        end--;
    }
    
    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    
    return 0;
}
