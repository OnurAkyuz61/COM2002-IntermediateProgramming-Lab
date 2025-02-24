#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

int main() {
    char word[MAX_LENGTH + 1];
    char smallest_word[MAX_LENGTH + 1];
    char largest_word[MAX_LENGTH + 1];
    int first_word = 1;
    
    while (1) {
        printf("Enter word: ");
        scanf("%s", word);
        
        // Check if word is four letters
        if (strlen(word) == 4) {
            break;
        }
        
        if (first_word) {
            strcpy(smallest_word, word);
            strcpy(largest_word, word);
            first_word = 0;
        } else {
            if (strcmp(word, smallest_word) < 0) {
                strcpy(smallest_word, word);
            }
            if (strcmp(word, largest_word) > 0) {
                strcpy(largest_word, word);
            }
        }
    }
    
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
    
    return 0;
}
