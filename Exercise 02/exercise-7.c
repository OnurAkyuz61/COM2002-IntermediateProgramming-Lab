#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_ROWS 3
#define NUM_COLUMNS 4

int main() {
    int values[NUM_ROWS][NUM_COLUMNS];
    int i, j;
    
    // Initialize array with zeros
    for(i = 0; i < NUM_ROWS; i++) {
        for(j = 0; j < NUM_COLUMNS; j++) {
            values[i][j] = 0;
        }
    }
    
    // Assign value 11 to column i of the array
    for(i = 0; i < NUM_ROWS; i++) {
        values[i][1] = 11;  // Column 1 (second column) gets value 11
    }
    
    // Print the array to verify
    printf("Array after assigning 11 to column i (1):\n");
    for(i = 0; i < NUM_ROWS; i++) {
        for(j = 0; j < NUM_COLUMNS; j++) {
            printf("%2d ", values[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
