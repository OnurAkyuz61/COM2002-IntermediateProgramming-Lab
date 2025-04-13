#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Sort the words
    quickSort(words, 0, size - 1);

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
