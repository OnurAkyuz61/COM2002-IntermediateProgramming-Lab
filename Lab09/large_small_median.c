#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    FILE *file;
    int numbers[10000]; // Array to store integers (max 10,000)
    int count = 0;      // Count of integers read
    int num;            // Temporary variable to read integers
    int largest, smallest, median;
    
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
    
    // Read integers from the file
    while (fscanf(file, "%d", &num) == 1 && count < 10000) {
        numbers[count++] = num;
    }
    
    fclose(file);
    
    // Check if any integers were read
    if (count == 0) {
        printf("No integers found in the file.\n");
        return 1;
    }
    
    // Sort the array
    qsort(numbers, count, sizeof(int), compare);
    
    // Find largest and smallest
    smallest = numbers[0];
    largest = numbers[count - 1];
    
    // Find median
    if (count % 2 == 1) {
        // Odd number of integers
        median = numbers[count / 2];
    } else {
        // Even number of integers - average of two middle values (rounded down)
        median = (numbers[(count / 2) - 1] + numbers[count / 2]) / 2;
    }
    
    // Display results
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    printf("Median: %d\n", median);
    
    return 0;
}
