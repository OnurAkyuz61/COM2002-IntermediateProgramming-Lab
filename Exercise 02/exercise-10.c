#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 6
#define NUM_COLUMNS 4

// Function prototype
int* find_middle(int a[], int n);

int main() {
    int values[NUM_ROWS][NUM_COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };
    
    // Find middle element in row 5
    int* middle = find_middle(values[5], NUM_COLUMNS);
    
    printf("Array contents:\n");
    for(int i = 0; i < NUM_ROWS; i++) {
        for(int j = 0; j < NUM_COLUMNS; j++) {
            printf("%2d ", values[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMiddle element in row 5: %d\n", *middle);
    
    return 0;
}

// Function implementation
int* find_middle(int a[], int n) {
    return &a[n / 2];
}
