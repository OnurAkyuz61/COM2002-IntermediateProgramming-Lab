#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    char letters[MAX_LENGTH];
    int len = 0;
    
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    // Store only letters (converted to lowercase) in the letters array
    for (int i = 0; message[i] != '\0' && message[i] != '\n'; i++) {
        if (isalpha(message[i])) {
            letters[len] = tolower(message[i]);
            len++;
        }
    }
    letters[len] = '\0';
    
    // Check if it's a palindrome
    int is_palindrome = 1;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (letters[i] != letters[j]) {
            is_palindrome = 0;
            break;
        }
    }
    
    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    
    return 0;
}
