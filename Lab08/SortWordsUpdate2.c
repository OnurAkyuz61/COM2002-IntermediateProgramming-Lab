#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to swap two strings
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort for array of strings
void selectionSort(char **arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            // Compare strings using strcmp
            if (strcmp(arr[j], arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

int main() {
    char **words = NULL;
    int capacity = 10;
    int size = 0;
    char input[MAX_WORD_LENGTH];

    // Initial memory allocation
    words = (char **)malloc(capacity * sizeof(char *));
    if (words == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read words until empty string is entered
    printf("Enter word: ");
    while (fgets(input, MAX_WORD_LENGTH, stdin) != NULL) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        
        // Break if empty string
        if (strlen(input) == 0) {
            break;
        }

        // Resize array if needed
        if (size >= capacity) {
            capacity *= 2;
            char **temp = (char **)realloc(words, capacity * sizeof(char *));
            if (temp == NULL) {
                printf("Memory allocation failed!\n");
                // Free previously allocated memory
                for (int i = 0; i < size; i++) {
                    free(words[i]);
                }
                free(words);
                return 1;
            }
            words = temp;
        }

        // Allocate memory for the new word
        words[size] = (char *)malloc((strlen(input) + 1) * sizeof(char));
        if (words[size] == NULL) {
            printf("Memory allocation failed!\n");
            // Free previously allocated memory
            for (int i = 0; i < size; i++) {
                free(words[i]);
            }
            free(words);
            return 1;
        }

        // Copy the word
        strcpy(words[size], input);
        size++;

        printf("Enter word: ");
    }

    // Sort the words using selection sort
    selectionSort(words, size);

    // Print sorted words
    printf("\nIn sorted order:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", words[i]);
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}