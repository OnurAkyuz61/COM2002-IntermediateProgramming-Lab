#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 3
#define NUM_COLUMNS 4

// Function prototype
int* find_middle(int a[], int n);

int main() {
    int values[NUM_ROWS][NUM_COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Find middle element in row i (row 1)
    int* middle = find_middle(values[1], NUM_COLUMNS);
    
    printf("Array contents:\n");
    for(int i = 0; i < NUM_ROWS; i++) {
        for(int j = 0; j < NUM_COLUMNS; j++) {
            printf("%2d ", values[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMiddle element in row 1: %d\n", *middle);
    
    return 0;
}

// Function implementation
int* find_middle(int a[], int n) {
    return &a[n / 2];
}
